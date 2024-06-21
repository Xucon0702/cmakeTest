#include "Version.h"
#include <string>


#ifdef VEHICLE_N51
#define VEHICLE_TYPE " BJEV N51 Poject "
#else
#define VEHICLE_TYPE " BJEV N50 Poject "
#endif


const char* GetVersionDescImp(const char* moduleName, const char* moduleVersion, \
                const char* systemDesc, const char* gitHash, const char* gitBranch, const char* compileTime)
{
    static const std::string s_version = \
        std::string("\n************************************************************\n") \
                  + "* SystemDesc:\t" + systemDesc + VEHICLE_TYPE + "\n" \
                  + "* ModuleDesc:\t" + moduleName + "-" + moduleVersion + "\n" \
                  + "* GitDesc:\t" + gitHash + " " + gitBranch + "\n" \
                  + "* CompileTime:\t" + compileTime + "\n" \
                  + "************************************************************\n";
    return s_version.c_str();
}