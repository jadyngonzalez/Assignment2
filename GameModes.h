#ifndef GameModes_h
#define GameModes_h

class GameModes
{
  public:
    GameModes();
    GameModes(char, char, char); //Used for setting diff game Modes
    ~GameModes();

    //Need user to select game type (C, D, M), mode (file, rand), and output (Enter, File, Pause)
    char type();
    char mode();
    char output();

    //going to switch on the char arg to select type later so we need a func to set the modes
    void setType(char);
    void setMode(char);
    void setOutput(char);

  private:
    char gameType;
    char boardType;
    char outputType;
};
#endif
