struct tx
{
    // Define a structure to hold ANSI escape codes for text formatting
    struct TextFormat 
    {
        const char* reset;
        const char* bright;
        const char* dim;
        const char* underscore;
        const char* blink;
        const char* reverse;
        const char* hidden;
    }format;
    // Define a structure to hold ANSI escape codes for text colors
    struct TextColor 
    {
        const char* black;
        const char* red;
        const char* green;
        const char* yellow;
        const char* blue;
        const char* magenta;
        const char* cyan;
        const char* white;
    }color;
    // Define a structure to hold ANSI escape codes for background colors
    struct BackgroundColor 
    {
        const char* black;
        const char* red;
        const char* green;
        const char* yellow;
        const char* blue;
        const char* magenta;
        const char* cyan;
        const char* white;
    }bgcolor;
};


