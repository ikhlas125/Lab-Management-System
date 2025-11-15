#include "DataManager.h"
void createTeachingAssistantsBinary() {
    TeachingAssistant tas[] = {{"TA001", "P003"}, {"TA002", "P004"}, {"TA003", "P005"}, {"TA004", "P006"}};

    ofstream file("teaching_assistants.bin", ios::binary);
    int count = 4;
    file.write((char*)&count, sizeof(int));
    file.write((char*)tas, sizeof(tas));
    file.close();
    cout << "teaching_assistants.bin created" << endl;
}
int main() {
    DataManager dm;
    createTeachingAssistantsBinary();
    dm.loadPersons();
    dm.loadInstructors();
    dm.loadTAs();
    dm.printPersons();
    dm.printInstructors();
    dm.printTAs();
    return 0;
}