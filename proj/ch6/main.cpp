/*
 * ===================================================================================
 *
 * C++ Interactive Walkthrough: Chapter 6 - Functions (Best Practices Edition)
 *
 * ===================================================================================
 *
 * Welcome! This is a single, runnable C++ source file designed to be an
 * interactive walkthrough of the concepts from Chapter 6.
 *
 * Instructions:
 * 1. Compile and run this file.
 * 2. A menu will appear in your console.
 * 3. Follow the menu options in order (1, 2, 3...) to see each
 * concept from the chapter explained and demonstrated.
 *
 * --- Best Practices Note ---
 *
 * This file avoids "namespace pollution."
 *
 * You will *not* see the line 'using namespace std;'.
 * That line is convenient but considered bad practice in larger projects
 * because it can cause function and variable name collisions.
 *
 * Instead, we will explicitly qualify all standard library components
 * with the 'std::' prefix, like 'std::cout', 'std::string', etc.
 * This is the professional and safer way to write C++ code.
 *
 * ===================================================================================
 *
 * This file itself demonstrates several concepts:
 *
 * - 6.1: Modular Programming
 * Instead of one giant 'main' function, this program is broken into many
 * small, manageable functions (e.g., 'demoPassByValue', 'demoOverloading').
 * This makes the code easier to read, test, and maintain.
 *
 * - 6.3: Function Prototypes
 * Notice that all the function "signatures" (their names, return types,
 * and parameters) are listed below, *before* the 'main' function.
 * This is a "Function Prototype." It tells the compiler "Hey, these
 * functions exist. I promise to give you the full definition later."
 * This allows us to place our 'main' function at the top for readability,
 * even though it calls functions defined later in the file.
 *
 * - 6.6: Menu-Driven Program
 * The 'main' function is a classic example of a menu-driven program.
 * It uses a loop to repeatedly show a menu and a 'switch' statement
 * to call the correct function based on user input.
 *
 * ===================================================================================
 */

// --- Required Libraries ---
// For console input/output (std::cout, std::cin, std::endl)
#include <iostream>

// For file input/output (std::ofstream) - as requested
#include <fstream>

// For the 'std::vector' data structure - as requested
#include <vector>

// --- Other Useful Libraries ---
// For 'std::string' objects
#include <string>

// For 'std::exit()' function (see 6.15)
#include <cstdlib>

// For 'std::setprecision' (formatting output)
#include <iomanip>

// For 'std::numeric_limits' (used in input clearing)
#include <limits>


/*
 * ===================================================================================
 *
 * 6.10: Local and Global Variables (Part 1: Global)
 *
 * ===================================================================================
 *
 * This is a GLOBAL VARIABLE. It is defined *outside* of all functions.
 *
 * Scope: It can be "seen" and used by *any* function in this file that
 * comes after its definition (which is all of them).
 *
 * Warning: Global variables are generally discouraged! They make code
 * hard to debug because any function can change its value at any time.
 * It's usually better to pass data into functions as parameters.
 * We include one here for demonstration purposes.
 */
int g_demoCounter = 0;


/*
 * ===================================================================================
 *
 * 6.3: Function Prototypes
 *
 * ===================================================================================
 *
 * Here are the prototypes for all the functions we will use.
 * The full definitions (the code *inside* the functions) are
 * written *after* the 'main' function.
 */

// --- Menu & Helper Functions ---
void displayMenu();
void clearInputBuffer();
void pressEnterToContinue();

// --- Chapter Concept Demo Functions ---
void demoDefiningAndCalling();     // 6.2
void demoSendingData(int num, std::string msg); // 6.4
void demoPassByValue();           // 6.5
void demoReturningValue();        // 6.8
void demoReturningBool();         // 6.9
void demoLocalVariables();        // 6.10
void demoStaticLocal();           // 6.11
void demoDefaultArgs();           // 6.12
void demoPassByReference();       // 6.13
void demoOverloading();           // 6.14
void demoExitFunction();          // 6.15
void demoFileIO();                // Demos <fstream>
void demoVectorPassing();         // Demos <vector>
void demoStubFunction();          // 6.16

// --- Functions *called by* our demo functions ---
void aSimpleVoidFunction();
int getNumberFromUser();
bool isEven(int num);
void functionWithAStaticVar();
void showMessage(std::string text, int times = 1); // 6.12: Has a default argument
void changeThisValue(int& refToValue); // 6.13: Takes a reference
int findArea(int side); // 6.14: Overloaded function 1
int findArea(int length, int width); // 6.14: Overloaded function 2
void printVector(const std::vector<int>& vec); // Demos passing a vector efficiently


/*
 * ===================================================================================
 *
 * main() Function
 *
 * ===================================================================================
 *
 * This is the entry point of our program.
 * As mentioned (6.6), it acts as a menu-driven "driver" (6.16)
 * to test and demonstrate all the other functions.
 */
int main()
{
    // Configure 'std::cout' for currency/decimal output
    std::cout << std::fixed << std::showpoint << std::setprecision(2);

    std::cout << "=========================================" << std::endl;
    std::cout << " Welcome to the C++ Functions Walkthrough" << std::endl;
    std::cout << "=========================================" << std::endl;

    int choice = 0;

    do
    {
        displayMenu();
        std::cin >> choice;

        // Check for bad input (e.g., user types 'a')
        if (std::cin.fail())
        {
            clearInputBuffer();
            choice = -1; // Set to an invalid choice
        }

        std::cout << std::endl;

        // Call functions based on user's choice
        switch (choice)
        {
        case 1:
            demoDefiningAndCalling();
            break;
        case 2:
            // 6.4: We are "sending data" (arguments) into this function
            demoSendingData(42, "Hello Functions!");
            break;
        case 3:
            demoPassByValue();
            break;
        case 4:
            demoReturningValue();
            break;
        case 5:
            demoReturningBool();
            break;
        case 6:
            demoLocalVariables();
            break;
        case 7:
            demoStaticLocal();
            break;
        case 8:
            demoDefaultArgs();
            break;
        case 9:
            demoPassByReference();
            break;
        case 10:
            demoOverloading();
            break;
        case 11:
            demoVectorPassing();
            break;
        case 12:
            demoFileIO();
            break;
        case 13:
            demoStubFunction();
            break;
        case 14:
            demoExitFunction();
            break;
        case 0:
            std::cout << "Exiting the walkthrough. Goodbye!" << std::endl;
            break;
        default:
            std::cout << "!!! Invalid choice. Please try again. !!!" << std::endl;
            break;
        }

        if (choice != 0 && choice != 14)
        {
            pressEnterToContinue();
        }

    } while (choice != 0);

    return 0; // 'return 0' tells the OS the program ran successfully.
}


/*
 * ===================================================================================
 * ===================================================================================
 *
 * FUNCTION DEFINITIONS
 *
 * This is where we provide the full code for all the functions
 * we promised to define in the "Prototypes" section.
 *
 * ===================================================================================
 * ===================================================================================
 */

/*
 * ===================================================================================
 *
 * 6.2: Defining and Calling Functions
 *
 * ===================================================================================
 *
 * A function "definition" includes the return type, name, parameters,
 * and the body (code) in { ... }.
 *
 * A "void" function (like this one) is a function that does *not*
 * return any value back to the code that called it. It just "does stuff."
 *
 * A function "call" is the statement that executes the function.
 * 'demoDefiningAndCalling()' is the *definition*.
 * 'aSimpleVoidFunction()' inside it is a *call*.
 */
void demoDefiningAndCalling()
{
    std::cout << "--- 6.2: Defining and Calling Functions ---" << std::endl;
    std::cout << "We are now *inside* the 'demoDefiningAndCalling' function." << std::endl;
    std::cout << "I am about to *call* another function named 'aSimpleVoidFunction'." << std::endl;
    std::cout << std::endl;

    // This is the "function call"
    aSimpleVoidFunction();

    std::cout << std::endl;
    std::cout << "We have returned to 'demoDefiningAndCalling'." << std::endl;
    std::cout << "The 'aSimpleVoidFunction' has finished." << std::endl;
}

// This is the *definition* for the function we called above.
void aSimpleVoidFunction()
{
    std::cout << "    > Hello from 'aSimpleVoidFunction'!" << std::endl;
    std::cout << "    > I am a 'void' function. I don't return a value." << std::endl;
    std::cout << "    > I'm just printing this message and then I'll be done." << std::endl;
}


/*
 * ===================================================================================
 *
 * 6.4: Sending Data into a Function
 *
 * ===================================================================================
 *
 * Arguments vs. Parameters:
 *
 * - Argument: The value you *send* to a function. (e.g., '42', "Hello")
 * - Parameter: The variable *inside* the function that *receives* the value.
 * (e.g., 'num', 'msg')
 *
 * In 'main', we called 'demoSendingData(42, "Hello Functions!")'
 * - '42' is the ARGUMENT.
 * - 'int num' is the PARAMETER that '42' is copied into.
 *
 * - "Hello Functions!" is the ARGUMENT.
 * - 'std::string msg' is the PARAMETER that "Hello Functions!" is copied into.
 */
void demoSendingData(int num, std::string msg)
{
    std::cout << "--- 6.4: Sending Data into a Function ---" << std::endl;
    std::cout << "We are inside 'demoSendingData'." << std::endl;
    std::cout << "This function received two parameters:" << std::endl;
    std::cout << "1. An 'int' parameter named 'num', which holds: " << num << std::endl;
    std::cout << "2. A 'std::string' parameter named 'msg', which holds: " << msg << std::endl;
    std::cout << std::endl;
    std::cout << "The global variable 'g_demoCounter' is also visible here: " << g_demoCounter << std::endl;
}


/*
 * ===================================================================================
 *
 * 6.5: Passing Data by Value
 *
 * ===================================================================================
 *
 * This is a critical concept. By default, C++ "passes by value."
 * This means the function receives a *COPY* of the argument.
 *
 * Any changes made to the parameter *inside* the function are
 * made to the copy, and the *original* variable in 'main'
 * is completely unaffected.
 */
void passByValueDemo(int val)
{
    std::cout << "    > We are now inside 'passByValueDemo'." << std::endl;
    std::cout << "    > The parameter 'val' received a *copy* of 'myNumber'." << std::endl;
    std::cout << "    > The copy's current value is: " << val << std::endl;
    
    val = 100; // Change the copy
    
    std::cout << "    > We just changed the *copy* to: " << val << std::endl;
    std::cout << "    > Now returning to 'main'..." << std::endl;
}

void demoPassByValue()
{
    std::cout << "--- 6.5: Passing Data by Value ---" << std::endl;
    int myNumber = 10;
    
    std::cout << "In 'demoPassByValue', 'myNumber' is currently: " << myNumber << std::endl;
    std::cout << "Calling 'passByValueDemo(myNumber)'..." << std::endl;
    std::cout << std::endl;

    passByValueDemo(myNumber); // Pass 'myNumber' by value

    std::cout << std::endl;
    std::cout << "We are back in 'demoPassByValue'." << std::endl;
    std::cout << "The 'myNumber' variable is *STILL*: " << myNumber << std::endl;
    std::cout << "It was *not* changed by the function, because the function only had a copy." << std::endl;
}


/*
 * ===================================================================================
 *
 * 6.8: Returning a Value from a Function
 *
 * ===================================================================================
 *
 * A function with a return type (like 'int', 'double', 'std::string')
 * can send *one* value back to the code that called it using
 * the 'return' keyword.
 *
 * The function 'getNumberFromUser' is a "value-returning function."
 * It returns an 'int'.
 */
int getNumberFromUser()
{
    int number;
    std::cout << "    > Please enter any whole number: ";
    std::cin >> number;

    // Check for bad input
    if (std::cin.fail())
    {
        clearInputBuffer();
        std::cout << "    > Invalid input. Defaulting to 0." << std::endl;
        return 0; // 6.7: The 'return' statement ends the function *immediately*.
    }

    return number; // Send this value back to 'demoReturningValue'
}

void demoReturningValue()
{
    std::cout << "--- 6.8: Returning a Value from a Function ---" << std::endl;
    std::cout << "We are about to call 'getNumberFromUser()'." << std::endl;
    std::cout << "This function will *return* an 'int' value." << std::endl;
    std::cout << "We will store that returned value in a new variable." << std::endl;
    std::cout << std::endl;

    int returnedValue = getNumberFromUser(); // The call is on the right of the '='

    std::cout << std::endl;
    std::cout << "We are back in 'demoReturningValue'." << std::endl;
    std::cout << "The value returned from the function was: " << returnedValue << std::endl;
    std::cout << "We can now use this value. " << returnedValue << " * 2 = " << (returnedValue * 2) << std::endl;
}


/*
 * ===================================================================================
 *
 * 6.9: Returning a Boolean Value
 *
 * ===================================================================================
 *
 * A 'bool' function returns either 'true' or 'false'.
 * These are extremely useful for testing conditions. You can
 * place the function call directly inside an 'if' statement.
 */
bool isEven(int num)
{
    // The modulo operator (%) gives the remainder of a division.
    // If 'num % 2' is 0, the number is even.
    if (num % 2 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
    
    // A shorter way to write the function above:
    // return (num % 2 == 0);
}

void demoReturningBool()
{
    std::cout << "--- 6.9: Returning a Boolean Value ---" << std::endl;
    std::cout << "We will ask for a number, then call 'isEven(number)'." << std::endl;
    
    int num = getNumberFromUser(); // We can re-use our other function!

    std::cout << "Calling 'isEven(" << num << ")' directly inside an 'if' statement..." << std::endl;

    // The function call 'isEven(num)' will execute first and
    // will "become" either 'true' or 'false'.
    if (isEven(num))
    {
        std::cout << "The function returned 'true'. The number " << num << " is EVEN." << std::endl;
    }
    else
    {
        std::cout << "The function returned 'false'. The number " << num << " is ODD." << std::endl;
    }
}


/*
 * ===================================================================================
 *
 * 6.10: Local Variables (Part 2: Local)
 *
 * ===================================================================================
 *
 * A "Local Variable" is defined *inside* a function.
 *
 * Scope: It is *only* visible and usable within the function
 * it is defined in. It is "local" to that function.
 *
 * Lifetime: It is created in memory when the function is called
 * and *destroyed* when the function ends.
 */
void demoLocalVariables()
{
    std::cout << "--- 6.10: Local Variables ---" << std::endl;
    
    // 'myLocalVar' is a LOCAL VARIABLE. It is only visible
    // inside 'demoLocalVariables'.
    int myLocalVar = 25;

    std::cout << "We defined 'myLocalVar' inside this function. Its value is: " << myLocalVar << std::endl;
    
    // 'g_demoCounter' is a GLOBAL variable. It is visible everywhere.
    std::cout << "The global 'g_demoCounter' is also visible. Its value is: " << g_demoCounter << std::endl;
    
    std::cout << "The parameters from 'demoSendingData' (like 'num' and 'msg') are *not* " << std::endl;
    std::cout << "visible here. They were local to that function." << std::endl;

    // We can increment the global variable.
    g_demoCounter++;
    std::cout << "We just incremented the global counter. It is now: " << g_demoCounter << std::endl;
    
    std::cout << "When this function ends, 'myLocalVar' will be destroyed." << std::endl;
}


/*
 * ===================================================================================
 *
 * 6.11: Static Local Variables
 *
 * ===================================================================================
 *
 * A "static" local variable is special.
 *
 * Scope: It is *still* local (only visible inside the function).
 *
 * Lifetime: It is *NOT* destroyed when the function ends.
 * It "persists" and retains its value between function calls.
 *
 * Initialization: It is initialized (to 0, or your value)
 * *only the very first time* the function is called.
 */
void functionWithAStaticVar()
{
    // 'callCount' is a STATIC LOCAL variable.
    // The 'static' keyword makes it persist.
    // This line 'int callCount = 0' only *actually* runs
    // the very first time 'functionWithAStaticVar' is called.
    static int callCount = 0;

    // 'regularVar' is a regular local variable.
    // It is created and set to 0 *every single time* this function runs.
    int regularVar = 0;

    callCount++;  // Increment the persistent variable
    regularVar++; // Increment the temporary variable

    std::cout << "    > 'static callCount' is: " << callCount << std::endl;
    std::cout << "    > 'regularVar' is:       " << regularVar << std::endl;
}

void demoStaticLocal()
{
    std::cout << "--- 6.11: Static Local Variables ---" << std::endl;
    std::cout << "We are about to call 'functionWithAStaticVar' three times." << std::endl;
    std::cout << "Watch how the 'static' variable remembers its value," << std::endl;
    std::cout << "but the 'regular' variable resets to 0 every time." << std::endl;
    std::cout << std::endl;

    std::cout << "First call:" << std::endl;
    functionWithAStaticVar();
    std::cout << std::endl;

    std::cout << "Second call:" << std::endl;
    functionWithAStaticVar();
    std::cout << std::endl;

    std::cout << "Third call:" << std::endl;
    functionWithAStaticVar();
}


/*
 * ===================================================================================
 *
 * 6.12: Default Arguments
 *
 * ===================================================================================
 *
 * You can provide a "default" value for a parameter in the
 * function prototype.
 *
 * Prototype was: 'void showMessage(std::string text, int times = 1);'
 *
 * This means if the user doesn't provide the 'times' argument,
 * it will automatically be set to 1.
 *
 * Note: Parameters with default arguments *must* come
 * at the end of the parameter list.

 */
void showMessage(std::string text, int times)
{
    std::cout << "    > 'showMessage' called. It will print '" << text << "' " << times << " time(s)." << std::endl;
    for (int i = 0; i < times; i++)
    {
        std::cout << "    > " << text << std::endl;
    }
}

void demoDefaultArgs()
{
    std::cout << "--- 6.12: Default Arguments ---" << std::endl;
    std::cout << "Our function prototype is 'void showMessage(std::string text, int times = 1)'" << std::endl;
    std::cout << std::endl;

    std::cout << "First, we call 'showMessage(\"Hello\", 3)'" << std::endl;
    std::cout << "We are providing *both* arguments, so the default is ignored." << std::endl;
    showMessage("Hello", 3);
    std::cout << std::endl;

    std::cout << "Second, we call 'showMessage(\"Goodbye\")'" << std::endl;
    std::cout << "We are *only* providing the 'text' argument." << std::endl;
    std::cout << "The 'times' parameter will use its default value of 1." << std::endl;
    showMessage("Goodbye"); // 'times' will default to 1
}


/*
 * ===================================================================================
 *
 * 6.13: Passing by Reference
 *
 * ===================================================================================
 *
 * This is the *other* way to pass parameters.
 * The ampersand (&) in the parameter list 'int& refToValue'
 * makes it a "Reference Parameter."
 *
 * A reference does *NOT* create a copy. Instead, the parameter
 * 'refToValue' becomes an *ALIAS* (another name) for the
 * original variable 'myNumber' from 'main'.
 *
 * Any changes made to the 'refToValue' *ARE* made
 * to the original 'myNumber'. The function can now
 * permanently change variables from outside its scope.
 */
void changeThisValue(int& refToValue)
{
    std::cout << "    > Inside 'changeThisValue'. The parameter 'refToValue' is an ALIAS." << std::endl;
    std::cout << "    > It is currently: " << refToValue << std::endl;
    
    refToValue = 500; // This is *directly* changing 'myNumber' back in the demo.
    
    std::cout << "    > We changed 'refToValue' to: " << refToValue << std::endl;
    std::cout << "    > Returning..." << std::endl;
}

void demoPassByReference()
{
    std::cout << "--- 6.13: Passing by Reference ---" << std::endl;
    std::cout << "This is the *opposite* of 'Pass by Value'." << std::endl;
    std::cout << "The parameter 'int& refToValue' uses an '&' to become a reference." << std::endl;
    std::cout << std::endl;
    
    int myNumber = 20;

    std::cout << "In 'demoPassByReference', 'myNumber' is: " << myNumber << std::endl;
    std::cout << "Calling 'changeThisValue(myNumber)'..." << std::endl;
    std::cout << std::endl;

    changeThisValue(myNumber); // Pass 'myNumber' by reference

    std::cout << std::endl;
    std::cout << "We are back in 'demoPassByReference'." << std::endl;
    std::cout << "The 'myNumber' variable is *NOW*: " << myNumber << std::endl;
    std::cout << "It *WAS* permanently changed by the function." << std::endl;
}


/*
 * ===================================================================================
 *
 * 6.14: Overloading Functions
 *
 * ===================================================================================
 *
 * "Overloading" means creating two or more functions
 * with the *SAME NAME* but *DIFFERENT PARAMETER LISTS*.
 *
 * The compiler is smart enough to figure out which
 * one to call based on the arguments you provide.
 *
 * Note: You *cannot* overload based on return type alone.
 * The parameters *must* be different (either in type or in number).
 */

// Overload 1: Calculates area of a square (1 parameter)
int findArea(int side)
{
    std::cout << "    > 'findArea(int)' (square) was called." << std::endl;
    return side * side;
}

// Overload 2: Calculates area of a rectangle (2 parameters)
int findArea(int length, int width)
{
    std::cout << "    > 'findArea(int, int)' (rectangle) was called." << std::endl;
    return length * width;
}

void demoOverloading()
{
    std::cout << "--- 6.14: Overloading Functions ---" << std::endl;
    std::cout << "We have two functions, both named 'findArea'." << std::endl;
    std::cout << " - findArea(int)" << std::endl;
    std::cout << " - findArea(int, int)" << std::endl;
    std::cout << std::endl;
    
    std::cout << "Calling 'findArea(7)'..." << std::endl;
    int squareArea = findArea(7);
    std::cout << "Result: " << squareArea << std::endl;
    std::cout << std::endl;

    std::cout << "Calling 'findArea(7, 10)'..." << std::endl;
    int rectArea = findArea(7, 10);
    std::cout << "Result: " << rectArea << std::endl;
    std::cout << std::endl;
    
    std::cout << "The compiler automatically called the correct version!" << std::endl;
}


/*
 * ===================================================================================
 *
 * Demonstrating <vector>
 *
 * ===================================================================================
 *
 * This demo shows how to use the <vector> library as requested.
 *
 * We will also demonstrate "Pass by Const Reference."
 *
 * Prototype: 'void printVector(const std::vector<int>& vec)'
 *
 * - 'const': This is a promise. It tells the compiler "I am
 * not allowed to change 'vec' inside this function."
 *
 * - '&': We pass by reference. Why? A vector could be *huge*
 * (millions of items). Passing by value (6.5) would mean
 * *copying* the entire huge vector, which is very slow.
 *
 * By passing by "const reference," we get the best of both worlds:
 * 1. The speed of a reference (no copying).
 * 2. The safety of pass-by-value (the function can't
 * change our original vector).
 *
 * This is the standard, modern C++ way to pass large objects.
 */
void printVector(const std::vector<int>& vec)
{
    std::cout << "    > Inside 'printVector'. Received vector with " << vec.size() << " elements." << std::endl;
    std::cout << "    > Printing vector contents: [ ";
    
    // We can use a range-based for loop to iterate over the vector
    for (int item : vec)
    {
        std::cout << item << " ";
    }
    std::cout << "]" << std::endl;

    // The line below would cause a COMPILER ERROR because 'vec' is 'const':
    // vec.push_back(100); 
}

void demoVectorPassing()
{
    std::cout << "--- Demo: Using <vector> and Pass by Const Reference ---" << std::endl;
    
    // Create a vector (a dynamic, resizable array)
    std::vector<int> myNumbers;
    myNumbers.push_back(10);
    myNumbers.push_back(20);
    myNumbers.push_back(30);

    std::cout << "In 'demoVectorPassing', we created a std::vector." << std::endl;
    std::cout << "We will pass it to 'printVector' by *const reference*." << std::endl;
    std::cout << "This is fast (no copy) and safe (const = can't be changed)." << std::endl;
    std::cout << std::endl;

    printVector(myNumbers);
    
    std::cout << std::endl;
    std::cout << "Back in 'demoVectorPassing'. Our 'myNumbers' vector is unchanged." << std::endl;
}


/*
 * ===================================================================================
 *
 * Demonstrating <fstream>
 *
 * ===================================================================================
 *
 * This demo shows how to use the <fstream> library as requested.
 * We will create an "output file stream" ('std::ofstream') to write
 * data from our program into a text file.
 */
void demoFileIO()
{
    std::cout << "--- Demo: Using <fstream> for File Output ---" << std::endl;

    // 1. Create an ofstream (output file stream) object.
    //    We will name our file "walkthrough_log.txt".
    std::ofstream outFile;

    // 2. Open the file. 'std::ios::app' means "append" -- add to the
    //    end of the file instead of wiping it out.
    outFile.open("walkthrough_log.txt", std::ios::app);

    // 3. Check if the file opened successfully.
    if (outFile.fail())
    {
        std::cout << "!!! Error: Could not open 'walkthrough_log.txt' for writing. !!!" << std::endl;
        return; // 6.7: 'return' to exit the function early.
    }

    std::cout << "Successfully opened 'walkthrough_log.txt'." << std::endl;
    
    // 4. Write to the file, just like you write to 'std::cout'.
    outFile << "--- Log from C++ Walkthrough ---" << std::endl;
    outFile << "The File I/O demo function was just run." << std::endl;
    
    int num = 5;
    outFile << "Testing 'isEven(5)': " << isEven(num) << " (0=false, 1=true)" << std::endl;
    outFile << "Global counter is: " << g_demoCounter << std::endl;
    outFile << "--------------------------------" << std::endl << std::endl;

    // 5. Close the file. This is very important!
    outFile.close();

    std::cout << "We just wrote several lines to 'walkthrough_log.txt'." << std::endl;
    std::cout << "Check the directory where you ran this program to see the file!" << std::endl;
}


/*
 * ===================================================================================
 *
 * 6.16: Stubs
 *
 * ===================================================================================
 *
 * A "Stub" is a dummy function. You use it as a placeholder
 * when you are building a large program.
 *
 * Imagine we need a 'calculateTax' function, but we don't
 * want to write all that complex logic yet. We just want
 * to make sure our menu *calls* it correctly.
 *
 * We create a "stub" that just prints a message.
 * Later, we can come back and write the real code.
 */
void demoStubFunction()
{
    std::cout << "--- 6.16: Stubs and Drivers ---" << std::endl;
    std::cout << "This program's 'main' function is a 'Driver'." << std::endl;
    std::cout << "It is a program designed to 'drive' and test other functions." << std::endl;
    std::cout << std::endl;
    std::cout << "We are about to call a 'Stub' function." << std::endl;
    std::cout << "It's a placeholder for a function we haven't finished." << std::endl;
    std::cout << std::endl;

    // This is the "stub"
    std::cout << "    > Function 'calculateTax' (STUB) was called." << std::endl;
    std::cout << "    > (Not implemented yet. Returning default value 0.0)" << std::endl;
    double tax = 0.0; // The stub would return a dummy value
    
    std::cout << std::endl;
    std::cout << "This lets us test our program's flow without" << std::endl;
    std::cout << "writing all the complex functions at once." << std::endl;
}


/*
 * ===================================================================================
 *
 * 6.15: The exit() Function
 *
 * ===================================================================================
 *
 * The 'std::exit()' function (from <cstdlib>) is very powerful
 * and very dangerous.
 *
 * 'return' just ends the *current function*.
 * 'std::exit()' ends the *ENTIRE PROGRAM*, immediately.
 *
 * It does not matter if it's in 'main' or a function
 * 50 calls deep. 'std::exit()' terminates everything.
 */
void demoExitFunction()
{
    std::cout << "--- 6.15: The std::exit() Function ---" << std::endl;
    std::cout << "This function will call 'std::exit(0)'." << std::endl;
    std::cout << "This will terminate the *entire program* immediately." << std::endl;
    std::cout << "You will not see the 'Press Enter' prompt or the menu again." << std::endl;
    std::cout << "Goodbye!" << std::endl;

    // 'std::exit(0)' means "terminate the program with success code 0"
    std::exit(0);

    // This line will NEVER be reached.
    std::cout << "You will never see this message." << std::endl;
}


/*
 * ===================================================================================
 *
 * Helper Functions
 *
 * ===================================================================================
 *
 * These are just utilities to make the 'main' function
 * cleaner and more robust. This is good "modular programming"!
 */

// Displays the main menu
void displayMenu()
{
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "           CHAPTER 6: FUNCTIONS           " << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    std::cout << " 1. Defining and Calling Functions (6.2)" << std::endl;
    std::cout << " 2. Sending Data (Arguments) (6.4)" << std::endl;
    std::cout << " 3. Pass by Value (6.5)" << std::endl;
    std::cout << " 4. Returning a Value (6.8)" << std::endl;
    std::cout << " 5. Returning a 'bool' (6.9)" << std::endl;
    std::cout << " 6. Local & Global Variables (6.10)" << std::endl;
    std::cout << " 7. Static Local Variables (6.11)" << std::endl;
    std::cout << " 8. Default Arguments (6.12)" << std::endl;
    std::cout << " 9. Pass by Reference (6.13)" << std::endl;
    std::cout << " 10. Overloading Functions (6.14)" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    std::cout << " 11. Bonus: Using <vector> (const ref)" << std::endl;
    std::cout << " 12. Bonus: Using <fstream> (File I/O)" << std::endl;
    std::cout << " 13. Stubs and Drivers (6.16)" << std::endl;
    std::cout << " 14. The 'std::exit()' Function (6.15)" << std::endl;
    std::cout << " 0. Quit" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "Enter your choice: ";
}

// Clears the input buffer after a 'std::cin' error
void clearInputBuffer()
{
    // Clear the error state
    std::cin.clear();
    
    // Ignore all remaining characters in the input buffer
    // up to the next newline.
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Pauses the program so the user can read the output
void pressEnterToContinue()
{
    std::cout << "\n... Press ENTER to return to the menu ...";
    clearInputBuffer(); // Clear any leftover input
    std::cin.get();     // Wait for the user to press Enter
}
