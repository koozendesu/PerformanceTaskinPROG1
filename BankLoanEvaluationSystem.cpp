#include <iostream>
#include <string>
#include <cmath> // For Calculations

using namespace std ;

int main () {

    // Variables
    string name ;
    int age ;
    int annualIncome ;
    char existingLoan ;
    int creditScore ;
    int loanTerm ;
    char proceedAns ;
    int loanAmount ;

    //For Loan Approval
    string ageApproval = "approved" ;
    string creditApproval = "approved" ;
    string termApproval = "approved" ;
    string loanAmountApproval1 = "approved" ;
    string loanAmountApproval2 = "approved" ;
    string loanAmountApproval3 = "approved" ;
    string status = "approved" ;
    string existingLoanApproval = "approved" ;

// Welcome Message

cout <<"Welcome to the Bank Loan Evaluation System!\n" ;
cout <<"We are here to assist you in evaluating and processing your loan application.\n" ;
cout <<"\n" ;
cout <<"Would you like to Evaluate a loan application? (Y/N): " ;
cin >> proceedAns ;

    // Data Input
    while (proceedAns == 'y' || proceedAns == 'Y') {
        cout <<"\n" ;
        cout <<"\n" ;
        cout <<"Please input your information below:\n " ;
        cout <<"Enter applicant's name: " ;
        cin.ignore() ;
        getline(cin, name) ;

        cout <<"Enter applicant's age: " ;
        cin >> age ;

        cout <<"Enter applicant's annual income: " ;
        cin >> annualIncome ;

        cout <<"Enter applicant's credit score: " ;
        cin >> creditScore ;

        cout <<"Enter loan amount requested: " ;
        cin >> loanAmount ;

        cout <<"Enter loan term (in years): " ;
        cin >> loanTerm ;

        cout <<"Does the applicant have an existing loan? (Y/N): " ;
        cin >> existingLoan ;

    // Limitations
    if (age < 21 || age > 60) {
        ageApproval = "rejected" ;
        status = "rejected" ;
    }
    else {
        status = "approved" ;
        ageApproval = "approved" ;
    }

    if (creditScore < 700) {
        creditApproval = "rejected" ;
        status = "rejected" ;
    }
    else {
          status = "approved" ;
          creditApproval = "approved" ;
    }
        

    if (loanTerm < 1 || loanTerm > 20) {
        termApproval = "rejected" ;
        status = "rejected" ;
    }
    else {
          status = "approved" ;
          termApproval = "approved" ;
    }

    if (loanAmount < 50000 && annualIncome < 30000) {
        loanAmountApproval1 = "rejected" ;
        status = "rejected" ;
    }
    else {
          status = "approved" ;
          loanAmountApproval1 = "approved" ;
    }
    if ((loanAmount > 50000 || loanAmount <= 100000) && annualIncome < 50000) {
        loanAmountApproval2 = "rejected" ;
        status = "rejected" ;
    }
    else {
          status = "approved" ;
          loanAmountApproval2 = "approved" ;
    }
    if (loanAmount > 100000 && annualIncome < 80000) {
        loanAmountApproval3 = "rejected" ;
        status = "rejected" ;
    }
    else {
          status = "approved" ;
          loanAmountApproval3 = "approved" ;
    }

    if (existingLoan == 'Y' || existingLoan == 'y') {
        existingLoanApproval = "rejected" ;
        status = "rejected" ;
    }
    else {
          status = "approved" ;
          existingLoanApproval = "approved" ;
    }

    // Computation
    if (status == "approved") {
        double annualInterestRate = 0.10 ;
        double monthlyInterestRate = annualInterestRate / 12 ;
        int totalMonths = loanTerm * 12 ;
        string rate = "10%" ;
        double monthlyAmortization = (loanAmount * monthlyInterestRate) / (1 - pow(1 + monthlyInterestRate, -totalMonths)) ;
    
    // Interest Rates
    if (annualIncome >= 100000) {
        annualInterestRate = 0.05 ;
        rate = "5%" ;
    }
    else {
        annualInterestRate = 0.10 ;
        rate = "10%" ;
    }
    if (annualIncome >= 50000) {
        annualInterestRate = 0.07 ;
        rate = "7%" ;
    }
    else {
        annualInterestRate = 0.10 ;
        rate = "10%" ;
    }

    // Result (Approved)
        cout <<"\n" ;
        cout <<"\n" ;
        cout <<"Loan Application Result for " << name << " :\n" ;
        cout <<"\n" ;
        cout <<"Status: Approved\n" ;
        cout <<"Applicable Interest Rate: " << rate << "\n" ;
        cout <<"Loan Term: " << loanTerm << " years\n" ;
        cout <<"Monthly Amortization: " << "$" << monthlyAmortization <<"\n" ;
    }
    
    //Output Message
    if (status == "rejected") {
        cout <<"\n" ;
        cout <<"Loan Application Result for " << name <<":\n" ;
        cout <<"Status: Rejected\n" ;
        cout <<"Reason(s): \n" ;
    }if (ageApproval == "rejected") {
        cout <<"- The applicant must be between 21 and 60 years old.\n" ;
    }if (creditApproval == "rejected") {
        cout <<"- The applicant's credit score must be atleast 700.\n" ;
    }if (termApproval == "rejected") {
        cout <<"- The loan term must be betwee 1 and 20 years.\n" ;
    }if (loanAmountApproval1 == "rejected") {
        cout <<"- Applicant must have an annual income at least Php 30,000 for loans under Php 50,000.\n" ;
    }if (loanAmountApproval2 == "rejected") {
        cout <<"- Applicant must have an annual income at least Php 50,000 for loans between Php 50,000 and Php 100,000.\n" ;
    }if (loanAmountApproval3 == "rejected") {
        cout <<"- Applicant must have an annual income at least Php 80,000 for loans over Php 100,000.\n" ;
    }if (existingLoanApproval == "rejected") {
        cout <<"- Applicant must not have an existing loan with the bank.\n" ;
    }

    
    
        cout <<"\n" ;
        cout <<"Do you want to evaluate another loan application? (Y/N): " ;
        cin >> proceedAns ;

    }

    cout <<"\n" ;
    cout <<"Exiting the loan evaluation system. Goodbye!" ;

    return 0 ;
}