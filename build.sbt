ThisBuild / version      := "0.1.0"
ThisBuild / scalaVersion := "2.12.18"
ThisBuild / organization := "io.github.decodesim"

lazy val root = (project in file("."))
  .settings(
    name := "decode-sim",
    libraryDependencies ++= Seq(
      "com.github.spinalhdl" %% "spinalhdl-core" % "1.10.2a",
      "com.github.spinalhdl" %% "spinalhdl-lib"  % "1.10.2a",
      compilerPlugin("com.github.spinalhdl" %% "spinalhdl-idsl-plugin" % "1.10.2a"),
      "org.scalatest" %% "scalatest" % "3.2.18" % Test
    ),
    Compile / scalaSource := baseDirectory.value / "src" / "main" / "scala",
    Test    / scalaSource := baseDirectory.value / "src" / "test" / "scala"
  )

fork := true
