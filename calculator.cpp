#include <iostream> // For standard input and output operations
#include <vector>   // For using the STL vector container
#include <fstream>  // For file input and output
#include <limits>   // For clearing input buffer after invalid input
#include <sstream>  // For string formatting using ostringstream
#include <iomanip>  // or controlling floating-point number precision

using namespace std;

// Calculator class encapsulates all calculator-related operations
class Calculator
{
private:
    vector<string> history; // Vector to store calculation history in memory

public:
    // Function to add two numbers
    double add(double a, double b)
    {
        return a + b;
    }

    // Function to subtract second number from first
    double subtract(double a, double b)
    {
        return a - b;
    }

    // Function to multiply two numbers
    double multiply(double a, double b)
    {
        return a * b;
    }

    // Function to divide first number by second
    double divide(double a, double b)
    {
        // Check for division by zero
        if (b == 0)
        {
            // Throw exception
            throw runtime_error("Error: Division by zero is not allowed.");
        }
        return a / b;
    }

    // Function to log a calculation to both vector and file
    void logOperation(const string &op)
    {
        // Store operation string in the in-memory vector
        history.push_back(op);                  
        ofstream file("history.txt", ios::app);
        // Check if file opened successfully
        if (file.is_open()) 
        {
            // Write operation to file
            file << op << endl; 
            // Close file
            file.close();
        }
    }

    // Function to display past operations from the history file
    void showHistory()
    {
        // Open history file in read mode
        ifstream file("history.txt");
        string line;
        cout << "\n--- Calculation History ---\n";

        // If file exists and opened successfully
        if (file.is_open())
        {
            // Read line by line
            while (getline(file, line))
            {
                // Output each line to console
                cout << line << endl;
            }
            // Close the file after reading
            file.close();
        }
        else
        {
            // Show message if file doesn't exist
            cout << "No history found.\n";
        }
    }

    // Main function to drive the calculator interaction
    void start()
    {
        // User menu selection
        int choice;
        // Flag to control the main loop
        bool running = true;

        // Main loop to keep program running
        while (running)
        {
            // Display the main menu options
            cout << "\n=== Command-Line Calculator ===\n";
            cout << "1. Add\n";
            cout << "2. Subtract\n";
            cout << "3. Multiply\n";
            cout << "4. Divide\n";
            cout << "5. Show History\n";
            cout << "6. Exit\n";
            cout << "Choose an option (1-6): ";
            // Read user choice
            cin >> choice;

            // Input validation: if input is invalid (not a number)
            if (cin.fail())
            {
                // Clear error state
                cin.clear();
                // Ignore invalid input                                       
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a number.\n";
                // Restart the loop
                continue;
            }

            // Handle arithmetic operations if user chooses 1–4
            if (choice >= 1 && choice <= 4)
            {
                // Variables for operands and result
                double a, b, result;
                cout << "Enter first number: ";
                cin >> a;
                cout << "Enter second number: ";
                cin >> b;

                try
                {
                    // String stream to format output
                    ostringstream ss;
                    // Set decimal precision to 2 places
                    ss << fixed << setprecision(2);
                    // Perform the selected operation
                    switch (choice)
                    {
                    case 1:
                        result = add(a, b);
                        ss << a << " + " << b << " = " << result;
                        break;
                    case 2:
                        result = subtract(a, b);
                        ss << a << " - " << b << " = " << result;
                        break;
                    case 3:
                        result = multiply(a, b);
                        ss << a << " * " << b << " = " << result;
                        break;
                    case 4:
                        result = divide(a, b);
                        ss << a << " / " << b << " = " << result;
                        break;
                    }
                    // Output result to user
                    cout << "Result: " << result << endl;
                    // Save formatted operation to file and memory
                    logOperation(ss.str());
                }
                // Catch and display exceptions (e.g., divide by zero)
                catch (const exception &e)
                {
                    cout << e.what() << endl; // Print error message
                }
            }
            else if (choice == 5)
            {
                // Show previous calculations from file
                showHistory(); 
            }
            else if (choice == 6)
            {
                // Set flag to false to exit the loop
                running = false;
            }
            else
            {
                // Inform user if the selected menu option is out of range
                cout << "Invalid option. Please choose between 1 and 6.\n";
            }
        }
    }
};

// Program entry point
int main()
{
    // Instantiate Calculator object
    Calculator calc;
    // Start calculator session
    calc.start();
    // Exit the program
    return 0;
}
