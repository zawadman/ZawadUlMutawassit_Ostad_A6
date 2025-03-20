#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Patient 
{
    int id;
    string name;
    int age;
    int severity;
};

//function to read patient details from input
vector<Patient> readPatients(int n)
{
    vector<Patient> patients;
    patients.reserve(n);
    cout << "Enter details for each patient (ID Name Age Severity):" << endl;
    for (int i = 0; i < n; ++i)
    {
        Patient p;
        cin >> p.id >> p.name >> p.age >> p.severity;
        patients.push_back(p);
    }
    return patients;
}

void sortPatients(vector<Patient>& patients)
{
    //sort using a bubble sort
    int size = patients.size();

    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - i - 1; ++j)
        {
            bool swapNeeded = false;

            if (patients[j].severity < patients[j + 1].severity)
            {
                swapNeeded = true;
            }
            else if (patients[j].severity == patients[j + 1].severity)
            {
                if (patients[j].age > patients[j + 1].age)
                {
                    swapNeeded = true;
                }
            }

            if (swapNeeded)
            {
                // Swap adjacent elements
                Patient temp = patients[j];
                patients[j] = patients[j + 1];
                patients[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n;
    cout << "Enter the number of patients: ";
    cin >> n;

    vector<Patient> patients = readPatients(n);

    sortPatients(patients);

    cout << "\nStored patient details:" << endl;
    for (const auto& p : patients)
    {
        cout << p.id << " " << p.name << " " << p.age << " " << p.severity << endl;
    }

    return 0;
}
