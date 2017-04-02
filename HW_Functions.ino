
/*************************************************
** FILE : HW_Functions
** This file contains functions which are used
** to asses the internal state of the board.
** Ideally, we would have functions which can run
** diagnostics. 
** All functions should be platform independant 
**************************************************/



/*************************************************
** f_BLinkLED 
** This function is used to communicate to the user
** that the board is indeed doing things
** TO DO: I plan to implement a blink code for debugging 
*/
void f_BlinkLED( void )
{
  /* We blink every UART_BLINK_RATE millisecods */
  if ( millis() > (g_LastBlinkTime + UART_BLINK_RATE) )
  {
		/* Log the current states to the debug port */
    Debug_LogOut();
		
		/* Display number of bytes available on comm port
		** Com port is used for real-time communication with
		** connected processor */
    LOG_PORT.println("> # Available on COMM_PORT: " + String(COMM_PORT.available()) );
		
		/* Toggle LED */
    LOG_PORT.println("> Blink ...");
    digitalWrite(HW_LED_PIN, g_LedState);
    g_LedState = !g_LedState;
    g_LastBlinkTime = millis();
  }
} /* End f_BLinkLED */




