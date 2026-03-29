
#include <stdint.h>
#include <string>
#include <memory>
#include <jni.h>
#include <iostream>

#include "VDecoderNode.h"
#ifdef TRACE
#include "verilated_???_c.h"
#endif
#include "VDecoderNode__Syms.h"

using namespace std;

class ISignalAccess{
public:
  virtual ~ISignalAccess() {}

  virtual void getAU8(JNIEnv *env, jbyteArray value) {}
  virtual void getAU8_mem(JNIEnv *env, jbyteArray value, size_t index) {}
  virtual void setAU8(JNIEnv *env, jbyteArray value, int length) {}
  virtual void setAU8_mem(JNIEnv *env, jbyteArray value, int length, size_t index) {}

  virtual uint64_t getU64() = 0;
  virtual uint64_t getU64_mem(size_t index) = 0;
  virtual void setU64(uint64_t value) = 0;
  virtual void setU64_mem(uint64_t value, size_t index) = 0;
};

class  CDataSignalAccess : public ISignalAccess{
public:
    CData *raw;
    CDataSignalAccess(CData *raw) : raw(raw){}
    CDataSignalAccess(CData &raw) : raw(addressof(raw)){}
    uint64_t getU64() {return *raw;}
    uint64_t getU64_mem(size_t index) {return raw[index];}
    void setU64(uint64_t value)  {*raw = value; }
    void setU64_mem(uint64_t value, size_t index){raw[index] = value; }
};


class  SDataSignalAccess : public ISignalAccess{
public:
    SData *raw;
    SDataSignalAccess(SData *raw) : raw(raw){}
    SDataSignalAccess(SData &raw) : raw(addressof(raw)){}
    uint64_t getU64() {return *raw;}
    uint64_t getU64_mem(size_t index) {return raw[index];}
    void setU64(uint64_t value)  {*raw = value; }
    void setU64_mem(uint64_t value, size_t index){raw[index] = value; }
};


class  IDataSignalAccess : public ISignalAccess{
public:
    IData *raw;
    IDataSignalAccess(IData *raw) : raw(raw){}
    IDataSignalAccess(IData &raw) : raw(addressof(raw)){}
    uint64_t getU64() {return *raw;}
    uint64_t getU64_mem(size_t index) {return raw[index];}
    void setU64(uint64_t value)  {*raw = value; }
    void setU64_mem(uint64_t value, size_t index){raw[index] = value; }
};


class  QDataSignalAccess : public ISignalAccess{
public:
    QData *raw;
    QDataSignalAccess(QData *raw) : raw(raw){}
    QDataSignalAccess(QData &raw) : raw(addressof(raw)){}
    uint64_t getU64() {return *raw;}
    uint64_t getU64_mem(size_t index) {return raw[index];}
    void setU64(uint64_t value)  {*raw = value; }
    void setU64_mem(uint64_t value, size_t index){raw[index] = value; }
};

class  WDataSignalAccess : public ISignalAccess{
public:
    WData *raw;
    uint32_t width;
    uint32_t wordsCount;
    bool sint;

    WDataSignalAccess(WData *raw, uint32_t width, bool sint) : 
      raw(raw), width(width), wordsCount((width+31)/32), sint(sint) {}

    uint64_t getU64_mem(size_t index) {
      WData *mem_el = &(raw[index*wordsCount]);
      return mem_el[0] + (((uint64_t)mem_el[1]) << 32);
    }

    uint64_t getU64() { return getU64_mem(0); }

    void setU64_mem(uint64_t value, size_t index)  {
      WData *mem_el = &(raw[index*wordsCount]);
      mem_el[0] = value;
      mem_el[1] = value >> 32;
      uint32_t padding = ((value & 0x8000000000000000l) && sint) ? 0xFFFFFFFF : 0;
      for(uint32_t idx = 2;idx < wordsCount;idx++){
        mem_el[idx] = padding;
      }

      if(width%32 != 0) mem_el[wordsCount-1] &= (1l << width%32)-1;
    }

    void setU64(uint64_t value)  {
      setU64_mem(value, 0);
    }
    
    void getAU8_mem(JNIEnv *env, jbyteArray value, size_t index) {
      WData *mem_el = &(raw[index*wordsCount]);
      uint32_t byteCount = wordsCount*4;
      uint32_t shift = 32-(width % 32);
      uint32_t backup = mem_el[wordsCount-1];
      uint8_t values[byteCount + !sint];
      if(sint && shift != 32) mem_el[wordsCount-1] = (((int32_t)backup) << shift) >> shift;
      for(uint32_t idx = 0;idx < byteCount;idx++){
        values[idx + !sint] = ((uint8_t*)mem_el)[byteCount-idx-1];
      }
      (env)->SetByteArrayRegion ( value, 0, byteCount + !sint, reinterpret_cast<jbyte*>(values));
      mem_el[wordsCount-1] = backup;
    }
  
    void getAU8(JNIEnv *env, jbyteArray value) {
      getAU8_mem(env, value, 0);
    }

    void setAU8_mem(JNIEnv *env, jbyteArray jvalue, int length, size_t index) {
      WData *mem_el = &(raw[index*wordsCount]);
      jbyte value[length];
      (env)->GetByteArrayRegion( jvalue, 0, length, value);
      uint32_t padding = (value[0] & 0x80 && sint) != 0 ? 0xFFFFFFFF : 0;
      for(uint32_t idx = 0;idx < wordsCount;idx++){
        mem_el[idx] = padding;
      }
      uint32_t capedLength = length > 4*wordsCount ? 4*wordsCount : length;
      for(uint32_t idx = 0;idx < capedLength;idx++){
        ((uint8_t*)mem_el)[idx] = value[length-idx-1];
      }
      if(width%32 != 0) mem_el[wordsCount-1] &= (1l << width%32)-1;
    }

    void setAU8(JNIEnv *env, jbyteArray jvalue, int length) {
      setAU8_mem(env, jvalue, length, 0);
    }
};

class Wrapper_8245782698718055341;
thread_local Wrapper_8245782698718055341 *simHandle8245782698718055341;

#include <chrono>
using namespace std::chrono;

class Wrapper_8245782698718055341{
public:
    uint64_t time;
    high_resolution_clock::time_point lastFlushAt;
    uint32_t timeCheck;
    bool waveEnabled;
    //VerilatedContext* contextp; //Buggy in multi threaded spinalsim
    VDecoderNode *top;
    ISignalAccess *signalAccess[40];
    #ifdef TRACE
	  Verilated???C tfp;
	  #endif
    string name;
    int32_t time_precision;

    Wrapper_8245782698718055341(const char * name, const char * wavePath, int seed){
      //contextp = new VerilatedContext;
      Verilated::randReset(2);
      Verilated::randSeed(seed);
      top = new VDecoderNode();

      simHandle8245782698718055341 = this;
      time = 0;
      timeCheck = 0;
      lastFlushAt = high_resolution_clock::now();
      waveEnabled = true;
      signalAccess[0] = new CDataSignalAccess( top->io_syndromeIn );
      signalAccess[1] = new CDataSignalAccess( top->io_loadEnable );
      signalAccess[2] = new CDataSignalAccess( top->io_start );
      signalAccess[3] = new CDataSignalAccess( top->io_startPeel );
      signalAccess[4] = new CDataSignalAccess( top->io_reset_n );
      signalAccess[5] = new CDataSignalAccess( top->io_neighborIn_north_valid );
      signalAccess[6] = new CDataSignalAccess( top->io_neighborIn_north_regionId );
      signalAccess[7] = new CDataSignalAccess( top->io_neighborIn_north_grown );
      signalAccess[8] = new CDataSignalAccess( top->io_neighborIn_north_parentDir );
      signalAccess[9] = new CDataSignalAccess( top->io_neighborIn_north_peeled );
      signalAccess[10] = new CDataSignalAccess( top->io_neighborIn_south_valid );
      signalAccess[11] = new CDataSignalAccess( top->io_neighborIn_south_regionId );
      signalAccess[12] = new CDataSignalAccess( top->io_neighborIn_south_grown );
      signalAccess[13] = new CDataSignalAccess( top->io_neighborIn_south_parentDir );
      signalAccess[14] = new CDataSignalAccess( top->io_neighborIn_south_peeled );
      signalAccess[15] = new CDataSignalAccess( top->io_neighborIn_east_valid );
      signalAccess[16] = new CDataSignalAccess( top->io_neighborIn_east_regionId );
      signalAccess[17] = new CDataSignalAccess( top->io_neighborIn_east_grown );
      signalAccess[18] = new CDataSignalAccess( top->io_neighborIn_east_parentDir );
      signalAccess[19] = new CDataSignalAccess( top->io_neighborIn_east_peeled );
      signalAccess[20] = new CDataSignalAccess( top->io_neighborIn_west_valid );
      signalAccess[21] = new CDataSignalAccess( top->io_neighborIn_west_regionId );
      signalAccess[22] = new CDataSignalAccess( top->io_neighborIn_west_grown );
      signalAccess[23] = new CDataSignalAccess( top->io_neighborIn_west_parentDir );
      signalAccess[24] = new CDataSignalAccess( top->io_neighborIn_west_peeled );
      signalAccess[25] = new CDataSignalAccess( top->io_linkOut_valid );
      signalAccess[26] = new CDataSignalAccess( top->io_linkOut_regionId );
      signalAccess[27] = new CDataSignalAccess( top->io_linkOut_grown );
      signalAccess[28] = new CDataSignalAccess( top->io_linkOut_parentDir );
      signalAccess[29] = new CDataSignalAccess( top->io_linkOut_peeled );
      signalAccess[30] = new CDataSignalAccess( top->io_state );
      signalAccess[31] = new CDataSignalAccess( top->io_regionId );
      signalAccess[32] = new CDataSignalAccess( top->io_correctionFlag );
      signalAccess[33] = new CDataSignalAccess( top->io_parentDir );
      signalAccess[34] = new CDataSignalAccess( top->io_matchDir );
      signalAccess[35] = new CDataSignalAccess( top->io_matchedWithId );
      signalAccess[36] = new CDataSignalAccess( top->io_peeled );
      signalAccess[37] = new CDataSignalAccess( top->io_syndrome );
      signalAccess[38] = new CDataSignalAccess( top->clk );
      signalAccess[39] = new CDataSignalAccess( top->reset );

      #ifdef TRACE
      Verilated::traceEverOn(true);
      top->trace(&tfp, 99);
      tfp.open((std::string(wavePath) + "wave" + ".???").c_str());
      #endif
      this->name = name;
      this->time_precision = Verilated::timeprecision();
    }

    virtual ~Wrapper_8245782698718055341(){
      for(int idx = 0;idx < 40;idx++){
          delete signalAccess[idx];
      }

      #ifdef TRACE
      if(waveEnabled) tfp.dump((vluint64_t)time);
      tfp.flush();
      tfp.close();
      #endif
      #ifdef COVERAGE
      VerilatedCov::write((("/Users/natashaprabhoo/git/QEC-Decoder-Sim/./simWorkspace/DecoderNode/$TEST/") + name + ".dat").c_str());
      #endif

      // Verilated::runFlushCallbacks();
      // Verilated::runExitCallbacks();

      //contextp->gotFinish(true);
      top->final();
      delete top;
      //delete contextp;
    }

};

double sc_time_stamp () {
  if(simHandle8245782698718055341 == NULL) return 0.0;
  return simHandle8245782698718055341->time;
}


void vl_finish(const char* filename, int linenum, const char* hier) VL_MT_UNSAFE {
    if (false && hier) {}
    VL_PRINTF(  // Not VL_PRINTF_MT, already on main thread
        "- %s:%d: Verilog $finish\n", filename, linenum);
   /*if (Verilated::threadContextp()->gotFinish()) {
        VL_PRINTF(  // Not VL_PRINTF_MT, already on main thread
            "- %s:%d: Second verilog $finish, exiting\n", filename, linenum);
        Verilated::runFlushCallbacks();
        Verilated::runExitCallbacks();
        std::exit(0);
    }*/
    Verilated::threadContextp()->gotFinish(true);
}

#ifdef __cplusplus
extern "C" {
#endif
#include <stdio.h>
#include <stdint.h>

#define API __attribute__((visibility("default")))


JNIEXPORT Wrapper_8245782698718055341 * API JNICALL Java_wrapper_1verilator_VerilatorNative_newHandle_18245782698718055341
  (JNIEnv * env, jobject obj, jstring name, jstring wavePath, jint seedValue){
    #if defined(_WIN32) && !defined(__CYGWIN__)
    srand(seedValue);
    #else
    srand48(seedValue);
    #endif
    const char* ch = env->GetStringUTFChars(name, 0);
    const char* wavePathCh = env->GetStringUTFChars(wavePath, 0);
    Wrapper_8245782698718055341 *handle = new Wrapper_8245782698718055341(ch, wavePathCh, seedValue);
    env->ReleaseStringUTFChars(name, ch);
    env->ReleaseStringUTFChars(wavePath, wavePathCh);
    return handle;
}

JNIEXPORT jboolean API JNICALL Java_wrapper_1verilator_VerilatorNative_eval_18245782698718055341
  (JNIEnv *, jobject, Wrapper_8245782698718055341 *handle){
   handle->top->eval();
   return Verilated::gotFinish();
}

JNIEXPORT jint API JNICALL Java_wrapper_1verilator_VerilatorNative_getTimePrecision_18245782698718055341
  (JNIEnv *, jobject, Wrapper_8245782698718055341 *handle){
  return handle->time_precision;
}

JNIEXPORT void API JNICALL Java_wrapper_1verilator_VerilatorNative_sleep_18245782698718055341
  (JNIEnv *, jobject, Wrapper_8245782698718055341 *handle, uint64_t cycles){
  #ifdef TRACE
  if(handle->waveEnabled) {
    handle->tfp.dump((vluint64_t)handle->time);
  }
  handle->timeCheck++;
  if(handle->timeCheck > 10000){
    handle->timeCheck = 0;
    high_resolution_clock::time_point timeNow = high_resolution_clock::now();
    duration<double, std::milli> time_span = timeNow - handle->lastFlushAt;
    if(time_span.count() > 1e3){
      handle->lastFlushAt = timeNow;
      handle->tfp.flush();
    }
  }
  #endif
  handle->time += cycles;
}

JNIEXPORT jlong API JNICALL Java_wrapper_1verilator_VerilatorNative_getU64_18245782698718055341
  (JNIEnv *, jobject, Wrapper_8245782698718055341 *handle, int id){
  return handle->signalAccess[id]->getU64();
}

JNIEXPORT jlong API JNICALL Java_wrapper_1verilator_VerilatorNative_getU64mem_18245782698718055341
  (JNIEnv *, jobject, Wrapper_8245782698718055341 *handle, int id, uint64_t index){
  return handle->signalAccess[id]->getU64_mem(index);
}

JNIEXPORT void API JNICALL Java_wrapper_1verilator_VerilatorNative_setU64_18245782698718055341
  (JNIEnv *, jobject, Wrapper_8245782698718055341 *handle, int id, uint64_t value){
  handle->signalAccess[id]->setU64(value);
}

JNIEXPORT void API JNICALL Java_wrapper_1verilator_VerilatorNative_setU64mem_18245782698718055341
  (JNIEnv *, jobject, Wrapper_8245782698718055341 *handle, int id, uint64_t value, uint64_t index){
  handle->signalAccess[id]->setU64_mem(value, index);
}

JNIEXPORT void API JNICALL Java_wrapper_1verilator_VerilatorNative_deleteHandle_18245782698718055341
  (JNIEnv *, jobject, Wrapper_8245782698718055341 * handle){
  delete handle;
}

JNIEXPORT void API JNICALL Java_wrapper_1verilator_VerilatorNative_getAU8_18245782698718055341
  (JNIEnv * env, jobject obj, Wrapper_8245782698718055341 * handle, jint id, jbyteArray value){
  handle->signalAccess[id]->getAU8(env, value);
}

JNIEXPORT void API JNICALL Java_wrapper_1verilator_VerilatorNative_getAU8mem_18245782698718055341
  (JNIEnv * env, jobject obj, Wrapper_8245782698718055341 * handle, jint id, jbyteArray value, uint64_t index){
  handle->signalAccess[id]->getAU8_mem(env, value, index);
}

JNIEXPORT void API JNICALL Java_wrapper_1verilator_VerilatorNative_setAU8_18245782698718055341
  (JNIEnv * env, jobject obj, Wrapper_8245782698718055341 * handle, jint id, jbyteArray value, jint length){
  handle->signalAccess[id]->setAU8(env, value, length);
}

JNIEXPORT void API JNICALL Java_wrapper_1verilator_VerilatorNative_setAU8mem_18245782698718055341
  (JNIEnv * env, jobject obj, Wrapper_8245782698718055341 * handle, jint id, jbyteArray value, jint length, uint64_t index){
  handle->signalAccess[id]->setAU8_mem(env, value, length, index);
}

JNIEXPORT void API JNICALL Java_wrapper_1verilator_VerilatorNative_enableWave_18245782698718055341
  (JNIEnv *, jobject, Wrapper_8245782698718055341 * handle){
  handle->waveEnabled = true;
}

JNIEXPORT void API JNICALL Java_wrapper_1verilator_VerilatorNative_disableWave_18245782698718055341
  (JNIEnv *, jobject, Wrapper_8245782698718055341 * handle){
  handle->waveEnabled = false;
}

#ifdef __cplusplus
}
#endif
     