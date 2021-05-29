//Programa: Monitoracao de planta usando Arduino
//Autor: FILIPEFLOP

//BRANCO VCC
//CINZA GND
//ROXO A0

#include <Wire.h>;
#include <LiquidCrystal_I2C.h>;

LiquidCrystal_I2C lcd(0x27,20,4);
 
#define pino_sinal_analogico A0

int valor_analogico;

void setup()
{
  Serial.begin(9600);

  //Inicializa o LCD e o backlight
  lcd.init();
  lcd.backlight();
}
 
void loop()
{
  //Le o valor do pino A0 do sensor
  valor_analogico = analogRead(pino_sinal_analogico);
 
  //Mostra o valor da porta analogica no serial monitor
  Serial.print("Porta analogica: ");
  Serial.print(valor_analogico);
 
  //Solo umido, acende o led verde
  if (valor_analogico > 0 && valor_analogico < 400)
  {
    limpar();
    sorriso1();
    //Serial.println(" Status: Solo umido");
     //lcd.setCursor(1, 1);
     //lcd.print(      "=) Solo umido "        );
     //lcd.setCursor(6, 2);
     //lcd.print(     valor_analogico        );   
  }
 
  //Solo com umidade moderada, acende led amarelo
  if (valor_analogico > 400 && valor_analogico < 800)
  {
    limpar();
    //Serial.println(" Status: Umidade moderada");
    //lcd.setCursor(4, 1);
     //lcd.print(      "=| Solo moderado"        );
     //lcd.setCursor(6, 2);
     //lcd.print(      valor_analogico        );

        lcd.setCursor(7, 1);
        lcd.print(      "(-) (#)"        );
        lcd.setCursor(3, 2);
        lcd.print(   "**************"    );
        lcd.setCursor(13, 3);
        lcd.print(           "(_)"  );
        lcd.setCursor(16, 0);
        lcd.print(   valor_analogico    );
  }
 
  //Solo seco, acende led vermelho
  if (valor_analogico > 800 && valor_analogico < 1024)
  {
    limpar();
    lcd.setCursor(7, 1);
    lcd.print(      "(-) (-)"        );
    lcd.setCursor(3, 2);
    lcd.print(   "**************"    );
    lcd.setCursor(1, 3);
    lcd.print( "**              **"  );
    lcd.setCursor(16, 0);
    lcd.print(   valor_analogico    );
  }
  
  delay(7000);
}

void limpar() {
  lcd.setCursor(0, 0);
  lcd.print("                    ");
  lcd.setCursor(0, 1);
  lcd.print("                    ");
  lcd.setCursor(0, 2);
  lcd.print("                    ");
  lcd.setCursor(0, 3);
  lcd.print("                    ");
}

void sorriso1() {
  lcd.setCursor(7, 1);
  lcd.print(      "(#) (#)"        );
  lcd.setCursor(1, 2);
  lcd.print( "**              **"  );
  lcd.setCursor(3, 3);
  lcd.print(   "**************"    );
  lcd.setCursor(16, 0);
  lcd.print(   valor_analogico    );

  delay(3000);

  lcd.setCursor(7, 1);
  lcd.print(      "(-) (-)"        );
  lcd.setCursor(1, 2);
  lcd.print( "**              **"  );
  lcd.setCursor(3, 3);
  lcd.print(   "**************"    );
  lcd.setCursor(16, 0);
  lcd.print(   valor_analogico    );

  delay(200);

  lcd.setCursor(7, 1);
  lcd.print(      "(#) (#)"        );
  lcd.setCursor(1, 2);
  lcd.print( "**              **"  );
  lcd.setCursor(3, 3);
  lcd.print(   "**************"    );
  lcd.setCursor(16, 0);
  lcd.print(   valor_analogico    );

  delay(200);

  lcd.setCursor(7, 1);
  lcd.print(      "(-) (-)"        );
  lcd.setCursor(1, 2);
  lcd.print( "**              **"  );
  lcd.setCursor(3, 3);
  lcd.print(   "**************"    );
  lcd.setCursor(16, 0);
  lcd.print(   valor_analogico    );

  delay(200);
  
  lcd.setCursor(7, 1);
  lcd.print(      "(#) (#)"        );
  lcd.setCursor(1, 2);
  lcd.print( "**              **"  );
  lcd.setCursor(3, 3);
  lcd.print(   "**************"    );
  lcd.setCursor(16, 0);
  lcd.print(   valor_analogico    );


}
