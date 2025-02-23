#ifndef NPC_H
#define NPC_H

#include <string>

class NPC {
public:
    NPC(const std::string& name, const std::string& dialog);
    std::string getName() const;
    std::string getDialog() const;
    void setQuest(const std::string& quest);
    std::string getQuest() const;

private:
    std::string name;
    std::string dialog;
    std::string quest;
};

#endif // NPC_H