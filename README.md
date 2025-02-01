The following contents in this repository are my files required in my Peformance Task in PROG 1

Below is the source code of my Bank Evaluation System (C++) :

#include <iostream>
#include <string>
#include <cmath> // For Calculations

using namespace std;

int main() {
    // Variables
    string name;
    int age;
    int annualIncome;
    char existingLoan;
    int creditScore;
    int loanTerm;
    char proceedAns;
    int loanAmount;

    // Welcome Message
    cout << "Welcome to the Bank Loan Evaluation System!\n";
    cout << "We are here to assist you in evaluating and processing your loan application.\n\n";
    cout << "Would you like to evaluate a loan application? (Y/N): ";
    cin >> proceedAns;

    while (proceedAns == 'y' || proceedAns == 'Y') {
        // Reset status to approved for each new application
        string status = "approved";

        // Data Input
        cout << "\nPlease input your information below:\n";
        cout << "Enter applicant's name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter applicant's age: ";
        cin >> age;

        cout << "Enter applicant's annual income: ";
        cin >> annualIncome;

        cout << "Enter applicant's credit score: ";
        cin >> creditScore;

        cout << "Enter loan amount requested: ";
        cin >> loanAmount;

        cout << "Enter loan term (in years): ";
        cin >> loanTerm;

        cout << "Does the applicant have an existing loan? (Y/N): ";
        cin >> existingLoan;

        // Limitations
        if (age < 21 || age > 60) status = "rejected";
        if (creditScore < 700) status = "rejected";
        if (loanTerm < 1 || loanTerm > 20) status = "rejected";
        if (loanAmount < 50000 && annualIncome < 30000) status = "rejected";
        if ((loanAmount > 50000 || loanAmount <= 100000) && annualIncome < 50000) status = "rejected";
        if (loanAmount > 100000 && annualIncome < 80000) status = "rejected";
        if (existingLoan == 'Y' || existingLoan == 'y') status = "rejected";

        // Computation
        if (status == "approved") {
            double annualInterestRate = (annualIncome >= 100000) ? 0.05 : (annualIncome >= 50000) ? 0.07 : 0.10;
            double monthlyInterestRate = annualInterestRate / 12;
            int totalMonths = loanTerm * 12;
            double monthlyAmortization = (loanAmount * monthlyInterestRate) / (1 - pow(1 + monthlyInterestRate, -totalMonths));

            // Result (Approved)
            cout << "\nLoan Application Result for " << name << " :\n";
            cout << "Status: Approved\n";
            cout << "Applicable Interest Rate: " << (annualInterestRate * 100) << "%\n";
            cout << "Loan Term: " << loanTerm << " years\n";
            cout << "Monthly Amortization: $" << monthlyAmortization << "\n";
        } else {
            // Output Message for Rejected Application
            cout << "\nLoan Application Result for " << name << ":\n";
            cout << "Status: Rejected\n";
            cout << "Reason(s):\n";
            if (age < 21 || age > 60) cout << "- The applicant must be between 21 and 60 years old.\n";
            if (creditScore < 700) cout << "- The applicant's credit score must be at least 700.\n";
            if (loanTerm < 1 || loanTerm > 20) cout << "- The loan term must be between 1 and 20 years.\n";
            if (loanAmount < 50000 && annualIncome < 30000) cout << "- Applicant must have an annual income of at least Php 30,000 for loans under Php 50,000.\n";
            if ((loanAmount > 50000 || loanAmount <= 100000) && annualIncome < 50000) cout << "- Applicant must have an annual income of at least Php 50,000 for loans between Php 50,000 and Php 100,000.\n";
            if (loanAmount > 100000 && annualIncome < 80000) cout << "- Applicant must have an annual income of at least Php 80,000 for loans over Php 100,000.\n";
            if (existingLoan == 'Y' || existingLoan == 'y') cout << "- Applicant must not have an existing loan with the bank.\n";
        }

        cout << "\nDo you want to evaluate another loan application? (Y/N): ";
        cin >> proceedAns;
    }

    cout << "\nExiting the loan evaluation system. Goodbye!";
    return 0;
}
