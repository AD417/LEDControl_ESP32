#include "callbacks.hpp"

#include <string>
#include <SimpleCLI.h>

#include "colors.hpp"
#include "Program.h"
#include "Animations/AlternatingAnimation.hpp"
#include "Animations/FillAnimation.hpp"
#include "Animations/FlashAnimation.hpp"
#include "Animations/KillAnimation.hpp"
#include "Animations/PulseAnimation.hpp"
#include "Animations/TransitionAnimation.hpp"
#include "Animations/WaveAnimation.hpp"

void altCallback(cmd* commandPointer) {
    Command cmd(commandPointer);

    Argument intArg = cmd.getArg("interval");
    Argument widthArg = cmd.getArg("width");
    Argument colorArg = cmd.getArg("color");
    Argument transArg = cmd.getArg("transition");

    unsigned long interval =   intArg.getValue().toInt();
    int width =                widthArg.getValue().toInt();
    String colorString =       colorArg.getValue();
    unsigned long transition = transArg.getValue().toInt();

    Program::color = getColorFromString(colorString);

    if (interval < 50) interval = 500;
    if (width < 2) width = 2;

    Animation * nextAnimation = new AlternatingAnimation(
        Program::color,
        interval,
        width
    );
    if (transition != 0) {
        nextAnimation = new TransitionAnimation(
            Program::anim,
            nextAnimation,
            transition
        );
        Program::isInterrupted = true;
    } else {
        delete Program::anim;
    }

    Program::anim = nextAnimation;
}

void colorCallback(cmd* commandPointer) {
    Command cmd(commandPointer);

    String colorString = cmd.getArg("color").getValue();
    Program::color = getColorFromString(colorString);

    Program::anim->updateColorTo(Program::color);
}

void echoCallback(cmd* commandPointer) {
    Command cmd(commandPointer);

    int argCount = cmd.countArgs();

    for (int i = 0; i < argCount; i++) {
        Serial.print(cmd.getArg(i).getValue());
        Serial.print(" ");
    }
    Serial.println("");
}

void fillCallback(cmd* commandPointer) {
    Command cmd(commandPointer);

    String colorString = cmd.getArg("color").getValue();
    unsigned long transition = cmd.getArg("transition").getValue().toInt();

    Program::color = getColorFromString(colorString);

    Animation * nextAnimation = new FillAnimation(
        Program::color
    );

    if (transition != 0) {
        nextAnimation = new TransitionAnimation(
            Program::anim,
            nextAnimation,
            transition
        );
        Program::isInterrupted = true;
    } else {
        delete Program::anim;
    }

    Program::anim = nextAnimation;
}

void flashCallback(cmd* commandPointer) {
    Command cmd(commandPointer);

    unsigned long duration = cmd.getArg("duration").getValue().toInt();
    String colorString = cmd.getArg("color").getValue();
    bool killAfter = cmd.getArg("kill").isSet();
    bool recursive = cmd.getArg("recursive").isSet();

    Program::flashColor = getColorFromString(colorString, true);

    Animation * nextAnimation;
    if (killAfter) {
        nextAnimation = new KillAnimation();
        delete Program::anim;
    } else {
        nextAnimation = Program::anim;
    }

    Animation * flashAnim = new FlashAnimation(
        duration, 
        Program::flashColor, 
        nextAnimation
    );

    Program::anim = flashAnim;
    Program::isInterrupted = true;
    Program::isRecursive = recursive;
}

void killCallback(cmd* commandPointer) {
    Command cmd(commandPointer);

    unsigned long transition = cmd.getArg("transition").getValue().toInt();

    Animation * nextAnimation = new KillAnimation();
    if (transition != 0) {
        nextAnimation = new TransitionAnimation(
            Program::anim,
            nextAnimation,
            transition
        );
        Program::isInterrupted = true;
    } else {
        delete Program::anim;
    }
    Program::anim = nextAnimation;
}

void pulseCallback(cmd* commandPointer) {
    Command cmd(commandPointer);

    Argument intArg = cmd.getArg("interval");
    Argument colorArg = cmd.getArg("color");
    unsigned long transition = cmd.getArg("transition").getValue().toInt();

    unsigned long interval = intArg.getValue().toInt();
    String colorString =     colorArg.getValue();

    Program::color = getColorFromString(colorString);

    if (interval < 500) interval = 500;

    Animation * nextAnimation = new PulseAnimation(
        Program::color,
        interval
    );

    if (transition != 0) {
        nextAnimation = new TransitionAnimation(
            Program::anim,
            nextAnimation,
            transition
        );
        Program::isInterrupted = true;
    } else {
        delete Program::anim;
    }
    Program::anim = nextAnimation;
}

void waveCallback(cmd* commandPointer) {
    Command cmd(commandPointer);

    Argument intArg = cmd.getArg("interval");
    Argument widthArg = cmd.getArg("wavelength");
    Argument colorArg = cmd.getArg("color");
    unsigned long transition = cmd.getArg("transition").getValue().toInt();

    unsigned long interval = intArg.getValue().toInt();
    double width =           widthArg.getValue().toDouble();
    String colorString =     colorArg.getValue();

    Program::color = getColorFromString(colorString);
    // TRANSITION!

    if (interval < 50) interval = 50;
    if (width < 2.0) width = 5.0;

    Animation * nextAnimation = new WaveAnimation(
        Program::color,
        interval,
        width
    );

    if (transition != 0) {
        nextAnimation = new TransitionAnimation(
            Program::anim,
            nextAnimation,
            transition
        );
        Program::isInterrupted = true;
    } else {
        delete Program::anim;
    }
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