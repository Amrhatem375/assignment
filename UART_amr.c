int x;
void main() {
  ANSELA= 0xFF;
  ANSELB= 0;
  ANSELC= 0;
  ANSELD= 0;
  TRISA= 0xFF;
  TRISB= 0;
  TRISC= 0;
  TRISD= 0;

  UART1_Init(9600);
  Delay_ms(100);
  while (1) {
  x = ADC_Read(1);
  if (x<1500) {
  UART_Write("No light detected, LEDs active");
  PORTC= 0xFF;
  PORTD= 0xFF;
  PORTB= 0xFF;
  Delay_ms(100);
  }
  else {
  UART_Write("Light detected, LEDs inactive");
  PORTC= 0;
  PORTB= 0;
  PORTD= 0;
  Delay_ms(100);
}
}
}