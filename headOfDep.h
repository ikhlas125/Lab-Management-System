#pragma once
#include "Person.h"

class HeadOfDep : public Person {
  private:
  public:
    HeadOfDep(const string& id, const string& name, const string& email, const string& phone);
    void displayInfo() const;
};