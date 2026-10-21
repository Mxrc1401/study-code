# Lab 1 Section IV: Requirements for an Alarm Clock App

1. Individual Preparation

 Functional Requirements
- FR1: The user can create a new alarm with a time.
- FR2: The user can edit or delete an existing alarm.
- FR3: The user can turn an alarm on or off without deleting it.
- FR4: The user can set an alarm to repeat on certain weekdays (Mon-Fri).
- FR5: The user can choose a sound for each alarm.
- FR6: When the alarm goes off, the user can press snooze. 
- FR7: When the alarm goes off, the user can stop it with one button.
- FR8: The app shows a list of all alarms and the time until the next alarm rings.
- FR9: The user can turn on vibration for an alarm.

### Non-Functional Requirements

- NFR1 (Reliability): The alarm has to ring at the right time, even if the app is closed.
- NFR2 (Performance): The app should start in less than 2 seconds.

### Refined Requirements

#### Example 1: Snooze (FR6)

| Level | Requirement |
|-------|-------------|
| User level | As a user I want to snooze the alarm so I can sleep a few minutes longer and still wake up. |
| System level | The system has to stop the alarm sound when snooze is pressed and play it again after the snooze time (default 5 min). This also has to work when the screen is locked. |
| Software level | When the snooze button is pressed, the software stops the audio, saves the new ring time (current time + snooze time) and registers a new timer with the OS alarm service. When the timer fires, the alarm screen opens again and the sound starts. |

#### Example 2: Alarm rings when app is closed (NFR1)

| Level | Requirement |
|-------|-------------|
| User level | As a user I want my alarm to always ring, so I don't miss my lecture in the morning. |
| System level | The alarm must ring at the set time even if the app is closed, the phone is in standby or was restarted. |
| Software level | The software registers each active alarm with the OS scheduler (e.g. AlarmManager on Android). Alarms are stored in local storage and get registered again after the phone reboots. |

## 2. Group Discussion

Notes from our group (3 people):

- Some of us had almost the same requirements (create alarm, snooze, repeat), we merged them into one.
- Open questions we talked about:
  - Time zones: what happens if I travel? We decided the alarm uses the local time of the phone.
  - Snooze: how often can you snooze? We said max 3 times, then the alarm stops.
  - Volume: should the alarm get louder slowly? We added this as an optional feature.
  - Vibration: can be turned on for each alarm separately.
- Shared document: the list from above + the merged requirements from the others.

## 3. Short Presentation

- Functional requirements: create/edit/delete alarm, repeat on weekdays, snooze, stop, sound, vibration, alarm name
- Non-functional requirements: reliability (alarm always rings on time) and usability (easy to make an alarm)
- Refined example: snooze (user -> system -> software level, see above)
- Ambiguity we had: how many times you can snooze and how long the snooze is. We decided 10 minutes and max 3 times.
