/*
 ** @ Author: Jakub Sulovsky <sulovjak@fit.cvut.cz>
 *  @ Date: 26/02/2022
*/

#pragma once

// PROMPTS
const char * const PROMPT_DATE = "Enter date: [DD/MM/YYYY]";
const char * const PROMPT_NAME = "Enter the name of the event. ";
const char * const PROMPT_PLACE = "Enter the place of the event. ";
const char * const PROMPT_ACTION = "Enter the command's number.";
const char * const PROMPT_NEW_NAME = "Enter the new name of the event.";
const char * const PROMPT_NEW_PLACE = "Enter the place of the event.";
const char * const PROMPT_ID = "Enter the Event ID";
const char * const TO_EDIT = "Specify, what you want to modify [Name, Place, Time, Back]";
const char * const TO_PRINT = "Enter the mode of calendar view [Daily, Weekly, Monthly]";
const char * const PROMPT_MONTH_NAME = "Enter the name of the month.";
const char * const PROMPT_YEAR = "Enter the year.";
const char * const PROMPT_PERIOD = "Enter the period of event repetition ( in weeks, max. 48 ).";
const char * const PROMPT_REPETITION_END = "Enter the date, till when do you want the event to be repeated.";
const char * const PROMPT_OPTION = "Enter the option, how you want to search for the events ( id, name, place )";
const char * const PROMPT_PATH = "Enter the path of the file";


// EVENT MESSAGES
const char * const EVENT_START = "Enter the begin of the event [HH:MM DD/MM/YYYY]";
const char * const EVENT_END = "Enter the end of the event [HH:MM DD/MM/YYYY]";
const char * const EVENT_SEARCH = "Search for events";


// COMMAND INFO MESSAGES
const char * const INFO_ADD = "Add new event";
const char * const INFO_EXPORT = "Export events from calendar";
const char * const INFO_IMPORT = "Import events to calendar";
const char * const INFO_EDIT = "Modify existing event";
const char * const INFO_VIEW = "Display events";
const char * const INFO_REP  = "Add event repetition";
const char * const INFO_FINDER = "Find free time";
const char * const INFO_END = "End.";


// ERROR MESSAGES
const char * const EMPTY = "There are no events in calendar, add some first.";
const char * const UNKNOWN_COMMAND = "Unknown command!";
const char * const UNKNOWN_EVENT = "Unknown event!";
const char * const INVALID_INPUT = "Invalid input!";
const char * const INVALID_VALUE = "Invalid value!";
const char * const NO_EVENTS = "No events with entered parameters were found!";

const char * const DASHES = "-----------------------------------------------------------";

const char * const WEEK_DAYS = "|        MONDAY         |        TUESDAY        |       WEDNESDAY       |       THURSDAY        |        FRIDAY         |       SATURDAY        |        SUNDAY         |";

