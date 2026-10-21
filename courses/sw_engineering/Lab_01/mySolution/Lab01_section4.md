
 Functional Requirements
- 1: The user can create a new alarm with a time.
- 2: The user can edit or delete an existing alarm.
- 3: The user can turn an alarm on or off without deleting it.
- 4: The user can set an alarm to repeat on certain weekdays (Mon-Fri).
- 5: The user can choose a sound for each alarm.
- 6: When the alarm goes off, the user can press snooze. 
- 7: When the alarm goes off, the user can stop it with one button.
- 8: The app shows a list of all alarms and the time until the next alarm rings.
- 9: The user can turn on vibration for an alarm.


Non-Functional Requirements

- 1 (Reliability): The alarm has to ring at the right time, even if the app is closed.
- 2 (Performance): The app should start in less than 2 seconds.



Refined Requirements

Snooze:
User level = As a user I want to snooze the alarm so I can sleep a few minutes longer and still wake up. 
System level = The system has to stop the alarm sound when snooze is pressed and play it again after the snooze time. This also has to work when the screen is locked. 
Software level = When the snooze button is pressed, the software stops the audio, saves the new ring time and registers a new timer with the alarm. 



Ambiguity we had

How many times you can snooze and how long the snooze is. We decided 10 minutes and max 3 times.
