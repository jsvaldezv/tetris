#pragma once
#include "../Helpers/Sizes.h"
#include "../Helpers/Colours.h"
#include <raylib.h>

class MainComponent
{
public:
    explicit MainComponent();
    ~MainComponent();

    void prepare();

    void process();

    void draw();

    void drawBackground();

private:



};
