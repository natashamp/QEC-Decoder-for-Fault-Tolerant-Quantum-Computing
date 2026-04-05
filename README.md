# ** Distributed, Hardware-Accelerated QEC Decoder for Fault-Tolerant Quantum Computing**

Decode-Sim is a high-performance hardware implementation of a Minimum Weight Perfect Matching (MWPM)-inspired decoder designed to perform real-time Quantum Error Correction (QEC). Built with SpinalHDL, the project targets the Surface Code — the most promising error-correction scheme for scalable quantum processors.

The core innovation is a **distributed grid architecture** that physically maps the decoding logic to the layout of the quantum chip, enabling massive parallelization and sub-microsecond latency.

---

## Table of Contents

- [The Problem](#the-problem-the-decoding-wall)
- [The Solution](#the-solution-hardware-native-decoding)
- [Architecture Overview](#architecture-overview)
- [Technical Stack](#technical-stack)
- [Project Phases](#project-phases)
  - [Phase 1 — Foundation and Single-Node Decoder](#phase-1--foundation-and-single-node-decoder)
  - [Phase 2 — Distributed Grid Architecture](#phase-2--distributed-grid-architecture)
  - [Phase 3 — Region-Growing Decoder Algorithm](#phase-3--region-growing-decoder-algorithm)
  - [Phase 4 — Pipelined Streaming Architecture](#phase-4--pipelined-streaming-architecture)
  - [Phase 5 — FPGA Synthesis and Hardware Validation](#phase-5--fpga-synthesis-and-hardware-validation)
  - [Phase 6 — Benchmarking, Optimization, and Integration](#phase-6--benchmarking-optimization-and-integration)
- [Getting Started](#getting-started)
- [Repository Structure](#repository-structure)
- [License](#license)

---

## The Problem: The "Decoding Wall"

In a fault-tolerant quantum computer, qubits are extremely fragile. They must be measured every ~1 microsecond to detect errors (syndromes). If a classical decoder cannot process these syndromes and calculate corrections faster than they are generated, a backlog forms and the quantum state collapses.

| Bottleneck | Description |
|---|---|
| **Software Latency** | CPU-based MWPM solvers (e.g., PyMatching, Sparse Blossom) achieve high accuracy but operate in the microsecond-to-millisecond range — too slow for real-time feedback at scale. |
| **Data Congestion** | Moving syndrome data out of the cryogenic fridge to a remote server and back adds round-trip latency that can exceed the error-correction deadline. |

The decoding wall is the point at which the decoder throughput falls below the syndrome generation rate, making continued computation impossible.

---

## The Solution: Hardware-Native Decoding

Decode-Sim moves the decoding intelligence directly onto an **FPGA or ASIC** co-located with the quantum control electronics, eliminating the data-movement bottleneck entirely.

### Key Technical Features

- **Distributed Processing Nodes** — Every stabilizer (check qubit) in the surface code maps to a dedicated logic cell in the hardware grid. There is no central bottleneck.

- **Region-Growing Algorithm** — Instead of solving a global optimization problem, the decoder uses a local "bubble-growth" approach. Syndrome regions expand outward cycle by cycle until they collide, forming matched pairs. This is an approximation of MWPM that trades a small accuracy penalty for orders-of-magnitude speed improvement.

- **SpinalHDL Framework** — Leverages Scala-based hardware description to generate parameterizable, type-safe RTL. A single codebase can produce optimized netlists for any code distance ($d = 3, 5, 7, \dots$).

- **Pipelined Architecture** — The decoder accepts a continuous stream of syndrome frames, overlapping the processing of frame $t$ with the ingestion of frame $t+1$, ensuring the decoding wall is never reached during deep quantum circuits.

---

## Architecture Overview

```
                        Surface Code Patch (d = 5)
                  ┌───────────────────────────────────┐
                  │  ●───○───●───○───●───○───●───○───● │   ● = Data Qubit
                  │  │   │   │   │   │   │   │   │   │ │   ○ = Measure Qubit
                  │  ○───●───○───●───○───●───○───●───○ │       (Stabilizer)
                  │  │   │   │   │   │   │   │   │   │ │
                  │  ●───○───●───○───●───○───●───○───● │
                  │  │   │   │   │   │   │   │   │   │ │
                  │  ○───●───○───●───○───●───○───●───○ │
                  │  │   │   │   │   │   │   │   │   │ │
                  │  ●───○───●───○───●───○───●───○───● │
                  └───────────────────────────────────┘
                                   │
                          Syndrome Extraction
                                   │
                                   ▼
              ┌─────────────────────────────────────────┐
              │         Decode-Sim Hardware Grid         │
              │                                         │
              │   ┌─────┐  ┌─────┐  ┌─────┐  ┌─────┐   │
              │   │Node │──│Node │──│Node │──│Node │   │
              │   │(0,0)│  │(0,1)│  │(0,2)│  │(0,3)│   │
              │   └──┬──┘  └──┬──┘  └──┬──┘  └──┬──┘   │
              │      │        │        │        │       │
              │   ┌──┴──┐  ┌──┴──┐  ┌──┴──┐  ┌──┴──┐   │
              │   │Node │──│Node │──│Node │──│Node │   │
              │   │(1,0)│  │(1,1)│  │(1,2)│  │(1,3)│   │
              │   └──┬──┘  └──┬──┘  └──┬──┘  └──┬──┘   │
              │      │        │        │        │       │
              │   ┌──┴──┐  ┌──┴──┐  ┌──┴──┐  ┌──┴──┐   │
              │   │Node │──│Node │──│Node │──│Node │   │
              │   │(2,0)│  │(2,1)│  │(2,2)│  │(2,3)│   │
              │   └──┬──┘  └──┬──┘  └──┬──┘  └──┬──┘   │
              │      │        │        │        │       │
              │   ┌──┴──┐  ┌──┴──┐  ┌──┴──┐  ┌──┴──┐   │
              │   │Node │──│Node │──│Node │──│Node │   │
              │   │(3,0)│  │(3,1)│  │(3,2)│  │(3,3)│   │
              │   └─────┘  └─────┘  └─────┘  └─────┘   │
              │                                         │
              └─────────────────────────────────────────┘
                                   │
                          Correction Vector
                                   │
                                   ▼
                        Quantum Control Electronics
```

Each **Node** is an independent finite-state machine that communicates only with its immediate neighbors (North, South, East, West). This nearest-neighbor communication pattern mirrors the locality of the surface code itself and is what enables the massive parallelism.

---

## Technical Stack

| Layer | Technology |
|---|---|
| **Hardware Description** | SpinalHDL (Scala 2.12) |
| **Build System** | SBT (Scala Build Tool) |
| **RTL Simulation** | Verilator / GHDL |
| **Verification** | Cocotb (Python) + SpinalHDL sim |
| **Error Model Input** | Stim (Google's circuit-level error simulator) |
| **Target FPGAs** | Xilinx UltraScale+ / Intel Stratix 10 |
| **Synthesis** | Vivado / Quartus Prime |

---

## Project Phases

### Phase 1 — Foundation and Single-Node Decoder

**Goal:** Establish the build environment, define core data types, and implement a single decoder node that can detect and classify a syndrome.

**What gets built:**

- **Project scaffolding** — `build.sbt` with SpinalHDL dependencies, directory layout (`src/main/scala`, `src/test/scala`), `.gitignore`, and simulation scripts.
- **Core data types** — Syndrome bundles, correction vectors, node-state enums, and grid-coordinate types. These are the "language" every module speaks.
- **Single `DecoderNode` component** — A self-contained SpinalHDL `Component` representing one stabilizer. It accepts a single syndrome bit, maintains an internal state machine (`Idle → Growing → Matched`), and outputs a local correction flag.
- **Simulation harness** — A SpinalHDL testbench that drives known syndrome patterns into the node and asserts correct state transitions.

**Why this comes first:** Every subsequent phase builds on these types and this single node. Getting the interface contracts right here prevents cascading rewrites later.

**Key deliverables:**
- `DecoderNode.scala` — single-node RTL
- `DecoderTypes.scala` — shared bundles and enums
- `DecoderNodeSim.scala` — simulation testbench
- Generated Verilog for the single node

---

### Phase 2 — Distributed Grid Architecture

**Goal:** Tile the single node into a parameterized 2D grid with nearest-neighbor interconnections.

**What gets built:**

- **`DecoderGrid` component** — A top-level SpinalHDL module parameterized by code distance `d`. It instantiates a `(d-1) × (d-1)` array of `DecoderNode` instances and wires each node to its four cardinal neighbors.
- **Neighbor communication interface** — A `NodeLink` bundle carrying region-ID, growth state, and boundary flags between adjacent nodes. Boundary nodes (edges of the grid) are handled with special tie-off logic that represents the virtual boundary of the surface code.
- **Grid-level I/O** — A top-level port that accepts a full syndrome frame (one bit per stabilizer) and outputs a full correction vector (one bit per data qubit).
- **Parameterization tests** — Verify that the grid instantiates correctly for $d = 3$, $d = 5$, and $d = 7$, and that neighbor wiring is topologically correct.

**Why this matters:** The grid is the physical backbone of the decoder. The distributed, local-only wiring is what guarantees $O(1)$ communication latency between neighbors regardless of code distance, keeping the architecture scalable.

**Key deliverables:**
- `DecoderGrid.scala` — parameterized grid instantiation and wiring
- `NodeLink.scala` — inter-node communication bundle
- `DecoderGridSim.scala` — grid-level topology verification tests
- Generated Verilog for $d = 3$ and $d = 5$ grids

---

### Phase 3 — Region-Growing Decoder Algorithm

**Goal:** Implement the Union-Find / region-growing decoding algorithm across the distributed grid.

**What gets built:**

- **Growth logic** — On each clock cycle, every syndrome-active node broadcasts a "grow" signal to its neighbors. Inactive neighbors that receive a grow signal join the expanding region and begin growing themselves on the next cycle. This creates the "bubble" effect.
- **Collision detection** — When two independently growing regions meet at a shared edge, the collision is detected. The colliding nodes flag the boundary, and both regions transition to the `Matched` state.
- **Boundary peeling** — After all regions have either matched with another region or reached the virtual boundary (edge of the grid), the correction is computed by "peeling" the matched clusters: tracing the shortest path between matched syndromes and flipping the data qubits along that path.
- **Stall / backpressure** — If growth takes more cycles than expected (high error rate), the module asserts a `stall` signal to pause syndrome ingestion.

**Why this is the core phase:** This is the decoding algorithm itself. The region-growing approach is an approximation of MWPM with $O(d^2)$ worst-case latency (proportional to the grid diameter) but $O(1)$ per-node logic — the critical tradeoff that makes hardware decoding feasible.

**Key deliverables:**
- Updated `DecoderNode.scala` — full FSM with `Idle → Growing → Merging → Matched → Peeling` states
- `RegionManager.scala` — distributed union-find tracker using root-node convergence
- `CorrectionExtractor.scala` — peeling decoder that outputs the final correction vector
- Cocotb / SpinalHDL tests with Stim-generated syndrome data for $d = 3$ and $d = 5$

---

### Phase 4 — Pipelined Streaming Architecture

**Goal:** Enable the decoder to process a continuous stream of syndrome frames without stalling, overlapping decode of frame $t$ with ingestion of frame $t+1$.

**What gets built:**

- **Double-buffered syndrome input** — While the grid is decoding the current frame, the next frame is being loaded into a shadow register. On decode completion, the buffers swap in a single cycle.
- **Pipeline controller** — A top-level FSM that orchestrates the `Load → Decode → Extract → Output` stages. It tracks frame IDs and ensures corrections are emitted in order.
- **Temporal matching (multi-round)** — In real QEC, syndrome frames arrive every measurement round, and the decoder must compare consecutive frames (detecting *changes* in syndromes, not raw values). This module computes the XOR of consecutive frames to produce "detection events" — the actual input to the region-growing algorithm.
- **AXI-Stream I/O wrapper** — Standard streaming interfaces (`tvalid`, `tready`, `tdata`, `tlast`) for integration with DMA engines and the rest of the FPGA fabric.

**Why pipelining is essential:** A single decode pass may take 5–20 clock cycles depending on error density. Without pipelining, the decoder would idle during I/O, halving throughput. The streaming architecture ensures the decoder is always working.

**Key deliverables:**
- `PipelineController.scala` — frame sequencing and buffer management
- `TemporalMatcher.scala` — consecutive-frame XOR for detection events
- `AxiStreamWrapper.scala` — AXI-Stream input/output ports
- Throughput tests proving back-to-back frame processing with no idle cycles

---

### Phase 5 — FPGA Synthesis and Hardware Validation

**Goal:** Synthesize the design for a real FPGA target, meet timing constraints, and validate on hardware.

**What gets built:**

- **Synthesis scripts** — Vivado (Xilinx) and Quartus (Intel) TCL scripts for automated build, place-and-route, and bitstream generation.
- **Timing closure** — Analyze and resolve critical paths. The target is a clock frequency high enough that the full decode latency (clock period × cycle count) stays under 1 microsecond for $d \leq 7$.
- **Resource utilization report** — Document LUT, FF, BRAM, and DSP usage per code distance. Verify that the design scales within the resource budget of the target FPGA.
- **On-chip validation** — Use Xilinx ILA (Integrated Logic Analyzer) or Intel SignalTap to capture live waveforms from the running decoder and compare against simulation golden vectors.
- **Loopback test** — Feed stored syndrome frames from BRAM into the decoder at full speed and verify the correction output matches expected values.

**Why hardware validation matters:** Simulation proves logical correctness; synthesis proves the design is physically realizable. Timing failures or resource overflows at this stage would require architectural changes, so this phase acts as a hard reality check.

**Key deliverables:**
- `synth/vivado/` — Vivado project and TCL automation
- `synth/quartus/` — Quartus project and TCL automation
- Timing and utilization reports for $d = 3, 5, 7$
- ILA/SignalTap capture logs confirming hardware correctness

---

### Phase 6 — Benchmarking, Optimization, and Integration

**Goal:** Measure decoder performance against published baselines, optimize critical paths, and prepare the design for integration with real quantum control stacks.

**What gets built:**

- **Accuracy benchmarks** — Run Stim-generated Monte Carlo error samples through the decoder and measure the logical error rate vs. physical error rate. Compare against PyMatching (software MWPM) to quantify the accuracy tradeoff of the region-growing approximation.
- **Latency benchmarks** — Measure worst-case and average decode latency in clock cycles across a range of physical error rates ($p = 0.001$ to $p = 0.01$) and code distances.
- **Throughput benchmarks** — Measure sustained syndrome frames per second under continuous streaming load.
- **Optimizations** — Based on profiling, apply targeted improvements: logic restructuring to shorten critical paths, pipeline stage balancing, and optional approximate-matching heuristics for high-error-rate regimes.
- **Integration adapter** — A lightweight bridge module that translates between Decode-Sim's AXI-Stream interface and the control protocol of a target quantum control system (e.g., Zurich Instruments SHFQA, Quantum Machines OPX+).

**Why this is the final phase:** A decoder is only useful if it is faster *and* accurate enough. This phase produces the evidence — latency vs. accuracy curves — that demonstrates Decode-Sim meets the requirements for real-time fault-tolerant QEC.

**Key deliverables:**
- `bench/` — benchmark scripts and result datasets
- Logical error rate vs. physical error rate plots for $d = 3, 5, 7$
- Latency distribution histograms
- Integration adapter for at least one quantum control platform
- Final project report / paper-ready figures

---

## Getting Started

### Prerequisites

- **Java JDK** 8 or 11
- **SBT** 1.x
- **Verilator** 4.2+ (for simulation)
- **Python** 3.8+ with `cocotb` and `stim` (for verification)

### Build and Simulate

```bash
# Clone the repository
git clone https://github.com/<your-username>/QEC-Decoder-Sim.git
cd QEC-Decoder-Sim

# Compile and generate Verilog
sbt "runMain decodesim.DecoderGridVerilog"

# Run SpinalHDL simulation tests
sbt test

# Run Cocotb tests (after Verilog generation)
cd verification/cocotb
make
```

---

## Repository Structure

```
QEC-Decoder-Sim/
├── build.sbt                          # SBT build configuration
├── project/
│   └── plugins.sbt                    # SBT plugins
├── src/
│   ├── main/scala/decodesim/
│   │   ├── DecoderTypes.scala         # Core bundles, enums, configs
│   │   ├── DecoderNode.scala          # Single stabilizer processing node
│   │   ├── NodeLink.scala             # Inter-node communication bundle
│   │   ├── DecoderGrid.scala          # Parameterized 2D grid of nodes
│   │   ├── RegionManager.scala        # Distributed union-find logic
│   │   ├── CorrectionExtractor.scala  # Peeling decoder for correction output
│   │   ├── PipelineController.scala   # Frame sequencing and double-buffering
│   │   ├── TemporalMatcher.scala      # Consecutive-frame XOR logic
│   │   └── AxiStreamWrapper.scala     # AXI-Stream I/O interface
│   └── test/scala/decodesim/
│       ├── DecoderNodeSim.scala       # Single-node testbench
│       ├── DecoderGridSim.scala       # Grid topology tests
│       └── DecoderSystemSim.scala     # Full system streaming tests
├── verification/
│   └── cocotb/
│       ├── test_decoder_node.py       # Cocotb node-level tests
│       ├── test_decoder_grid.py       # Cocotb grid-level tests
│       └── Makefile
├── synth/
│   ├── vivado/                        # Xilinx synthesis scripts
│   └── quartus/                       # Intel synthesis scripts
├── bench/                             # Benchmarking scripts and results
└── README.md
```

---

## License

This project is released under the [MIT License](LICENSE).
