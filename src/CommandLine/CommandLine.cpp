#include "CommandLine.hpp"
#include <SimpleCLI.h>

#include "callbacks.hpp"

SimpleCLI commandLine;

Command altCommand = commandLine.addCommand("alt/ernate", altCallback);
Command fillCommand = commandLine.addCommand("fill,on", fillCallback);

void initCommandLine() {

    commandLine.setOnError(errorCallback); // Set error Callback

    // MUST be run before commands can be used!
    altCommand.addPositionalArgument("interval", "500");
    altCommand.addPositionalArgument("width", "5");
    altCommand.addArgument("c,color", "");
    // TRANSITION!

    fillCommand.addArgument("c,color", "");
    // TRANSITION!
}