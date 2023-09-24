#include "callbacks.hpp"

#include <string>
#include <SimpleCLI.h>

#include "colors.hpp"
#include "Program.h"
#include "Animations/AlternatingAnimation.hpp"
#include "Animations/FillAnimation.hpp"

void altCallback(cmd* commandPointer) {
    Command cmd(commandPointer);

    Argument intArg = cmd.getArg("interval");
    Argument widthArg = cmd.getArg("width");
    Argument colorArg = cmd.getArg("color");

    Serial.println(intArg.getValue());
    Serial.println(widthArg.getValue());
    Serial.println(colorArg.getValue());

    unsigned long interval = intArg.getValue().toInt();
    int width =              widthArg.getValue().toInt();
    String colorString =     colorArg.getValue();

    Program::color = getColorFromString(colorString);
    // TRANSITION!

    if (interval < 50) interval = 500;
    if (width < 2) width = 2;

    Animation * nextAnimation = new AlternatingAnimation(
        Program::color,
        interval,
        width
    );
    // TRANSITION!!!!

    delete Program::anim;
    Program::anim = nextAnimation;
}

void fillCallback(cmd* commandPointer) {
    Command cmd(commandPointer);

    String colorString = cmd.getArg("color").getValue();

    Program::color = getColorFromString(colorString);

    Animation * nextAnimation = new FillAnimation(
        Program::color
    );
    // TRANSITION!!!

    delete Program::anim;
    Program::anim = nextAnimation;
}

// Callback in case of an error
void errorCallback(cmd_error* e) {
    CommandError cmdError(e); // Create wrapper object

    Serial.print("ERROR: ");
    Serial.println(cmdError.toString());

    if (cmdError.hasCommand()) {
        Serial.print("Did you mean \"");
        Serial.print(cmdError.getCommand().toString());
        Serial.println("\"?");
    }
}