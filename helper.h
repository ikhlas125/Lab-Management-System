struct PersonRecord {
    char id[10];
    char name[50];
    char email[50];
    char phone[20];
};

struct InstructorRecord {
    char instructorId[10];
    char personId[10];
};

struct TeachingAssistant {
    char taId[10];
    char personId[10];
};

struct AcademicOfficerR {
    char officerId[10];
    char personId[10];
};

struct AttendantR {
    char attendantId[10];
    char personId[10];
    char buildingId[10];
};

struct HeadOfDepartmentR {
    char hodId[10];
    char personId[10];
};

struct BuildingR {
    char buildingId[10];
    char buildingName[50];
    char address[100];
    char attendantPersonId[10];
};

struct RoomR {
    char roomId[10];
    char roomNumber[20];
    int capacity;
    char buildingId[10];
    int floor;
};

struct LabR {
    char labId[10];
    char labCode[20];
    char labName[50];
    int credits;
    char semester[20];
};

struct LabSectionR {
    char sectionId[10];
    char labId[10];
    char sectionNumber[5];
    char instructorId[10];
    char semester[20];
    char academicYear[15];
};