#include "globals.h"
#include <stdbool.h> // For using 'bool' type

// Define names to be displayed
char* names[] = {"Your Name", "Partner Name 1", "Partner Name 2"};
int currentNameIndex = 0;

// Variable to track if the button was previously pressed
bool buttonPreviouslyPressed = false;

// Function declarations
void scrollName(char* name);

int main(void) {
    // Initialize the LCD and other necessary components
    init();
    init_lcd();
    clear_screen();

    while(1) {
        // Scroll the current name on the LCD
        scrollName(names[currentNameIndex]);

        // Check the button state
        bool buttonPressed = get_btn() != 0; // Assuming get_btn returns non-zero if button is pressed

        // If the button is pressed and was not pressed before, switch to the next name
        if (buttonPressed && !buttonPreviouslyPressed) {
            // Increment the name index and wrap around if it exceeds the number of names
            currentNameIndex = (currentNameIndex + 1) % 3; // Assuming there are 3 names

            // Update the button state
            buttonPreviouslyPressed = true;

            // Debounce delay
            _delay_ms(500); // Adjust delay as necessary
        } else if (!buttonPressed) {
            // Reset the button state when it's released
            buttonPreviouslyPressed = false;
        }
    }
    return 0;
}

void scrollName(char* name) {
    int len = strlen(name);
    for (int position = 0; position < len; position++) {
        // Set the cursor to start of LCD and print substring
        lcd_cursor(0, 0);
        print_string(name + position);

        // Delay to allow for the scrolling effect
        _delay_ms(300); // Adjust delay as necessary

        // Clear screen for the next position
        clear_screen();
    }
}
