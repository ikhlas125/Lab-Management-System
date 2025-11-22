#pragma once
#include "Person.h"

class HeadOfDep : public Person {
  private:
    string HeadOfDepId;

  public:
    HeadOfDep(const string& id, const string& name, const string& email, const string& phone, const string& hodid);

    string getHODId() const;

    void displayInfo() const;
};