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