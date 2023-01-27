int _ABVAR_1_pinA1 = 0 ;
int __ardublockAnalogRead(int pinNumber)
{
  pinMode(pinNumber, INPUT);
  return analogRead(pinNumber);
}


double _ABVAR_2_VA1 = 0.0 ;
double _ABVAR_3_Rpt1000 = 0.0 ;
double _ABVAR_4_T = 0.0 ;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  _ABVAR_1_pinA1 = __ardublockAnalogRead(A1) ;
  _ABVAR_2_VA1 = ( ( _ABVAR_1_pinA1 * 5.00 ) / 1024 ) ;
  _ABVAR_3_Rpt1000 = ( 1000 * ( _ABVAR_2_VA1 / ( 5 - _ABVAR_2_VA1 ) ) ) ;
  _ABVAR_4_T = ( ( _ABVAR_3_Rpt1000 - 1000 ) / 3.85 ) ;
  Serial.print("La temperatura medida en grados centgrados es:");
  Serial.print(" ");
  Serial.print(_ABVAR_4_T);
  Serial.print(" ");
  Serial.println();
  delay( 10000 );
}
