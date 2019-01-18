/*
 *  Copyright (C) 2018 - Handiko Gesang - www.github.com/handiko
 *  
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#include <avr/pgmspace.h>

#define CLK   PB3
#define FQ    PB2
#define DATA  PB1
#define RST   PB0

#define TD    1

unsigned long freq=35000000;

#define CAT_WIDTH  100
#define CAT_HEIGHT 71
const byte cat[CAT_HEIGHT][CAT_WIDTH + 1] PROGMEM = {
"                                               aaaaa                             aaa                ",
"                                              aa   aaa                         aaaaaa               ",
"                                              aa a  aaaa                      aa    aa              ",
"                                               a  aa aaaa                    aa  a  aa              ",
"                                               a  aaa aaaaa                 aa    a  a              ",
"                                               aa  aa  aa aa               aa  aaaaa a              ",
"                                                a  aa      aaa            aa  aaaa   aa             ",
"                                                a   aaa  a   aaaaaaaaaaaaaa    aa    aa             ",
"                                                aa   aa   a   aaa      aaa   aaa     aa             ",
"                                                 a  aaa   a a    a    aaa    aaa a   aa             ",
"                 aaaaaaa                         aa aaa   a     a    aa      aa  a   aa             ",
"               aaaa    a                          a aaa      a  a  aaa       aa  a  aaa             ",
"              aaa      a                          a aaaa    a     a a        aa  a  aa              ",
"             aaa       a                          aaaaa     a  a aaaa         a    a a              ",
"            aaaa       a                           aaa     aa    a a             a a a              ",
"            a a       a                            aa a   aa    aa a              a  a              ",
"           aaaa      aa                            aaaa  aaa    a a  a           aa aa              ",
"          aa aa     aa                             a a  aaa       a a            aa aa              ",
"          a        aa                              a a aa a      aaaa             aa a              ",
"         aa  a     aa                              a aaa  a     aa                 a a              ",
"         aa  a     a                               a aaaa       a  aa                aa             ",
"         a        aa                              aa a aaa       aaaaaa             aaa             ",
"         a        aa                              aaaa a a      aa aa a  a          aaaa            ",
"        aa        aa                              aaa a  a      aa aa a aaaaaaaaa   aa aa           ",
"        aa        aa                              aaaaaaaa     aaaa  a    aaaaaaaa  aa aaa          ",
"        aa        aa                              aa     a     a  aaa    aaa       aaa a aa         ",
"        aa        aa                               a a   a     a  aaaaaaaaa        aa a   aa        ",
"        aa        aa                               aa            aaa              aaa      aa       ",
"         a        aa                               aaa  a       a  aaaaaaaaa      aaaa      a       ",
"         aa        a                            aaaaaa  aaaaaa  a aa              aa a      a       ",
"         aa        aa                           aaaaaaa a aaaa      aaaa         aaaa       aa      ",
"          aa        a                        aaaaaaaaaaa aaaa   a a    aa       aaaa        aa      ",
"          aaa       aa               aaaaaaaaaaa a   aaaaaa   aaaaa  aaa a     aaaa     a   aaa     ",
"           aaa       aa       a   aaaaaa  aa       aaaaaa aa  a aa aaa  aaaa  aaaa   aaaa    aaa    ",
"            aaa       aaa      aaaaa            aa    aaaaaa  aaa  a  a   a   aaaa  aaa a    a aa   ",
"            aaaaa      aaaaaaaaaa         a   a     aaaa   aaaaaaaa a  a     aaa  aaa   a       a   ",
"             aaaaa      aaaaaaa          a         a  aaa      a  a  a  a   aaa  aa     a       aa  ",
"              aaaaa   aaaaa              a      aaaa a  aaa    a   a  aaaa aa    aa     a        a  ",
"               aaaaaaaaa a   a       a   a a   a    a   aaaaaaaaaaaaaaaa    aa aaa a    a        a  ",
"             a   aaa aa  a   aaa       aaa   aa      aa aa  aaaaaaaaa   aaa   aaaa    aa         aa ",
"            aaaaaa                 a               a    a  a     aa  a     a aaa                  a ",
"       aaaaaaaa         a    a                         aa   aaa    a     aaaaaa          a        aa",
"     aaaa                  a a    a                    aa    a        a aaaa              a       aa",
"   aaa             aaaaaaaaaaaaaa    aa               aa      aa      aaa                  a      aa",
"  aa             aaa         aaaaaaaaaa               aa       aa    aa             aa     aa    a a",
" aaa         aaaaa                    a               a        aa    a           aaa        a    a a",
" a         aaaa                       a              aaaa a     a             aaaa          aa     a",
"aa a     aa                         a                aa aaa     aa           aaa            aa   a a",
"aaa     aaaaa                     a                  aa   aaaa  a           aaa             aa  aa a",
"aa    a a                          a                aa     aaa             aa                a  a aa",
" aaaaa aaaa                      aa   a            aa aa    aaa            a                aa    aa",
"   aaaaaaaaa        aa   aaaaaaaaaaa              aaaaaaaa   a a          a                  aa   a ",
"        aa     a aaaaaaaaaa  aaaaaaaaaaaaaa       aa aaaaa   aaaa        a                    aa aa ",
"        aaaaaaaaaa                       aaaaaaaaaa     aaaa  aaa                            a a aa ",
"          aaaaaa                             aaaaa        aaa aaaa                            aaaaa ",
"                                                aa a       aa  aaa               aaa   aa  a   aaaa ",
"                                               aa  aa       aa  aa       aaaaaaaaaaaaaaa    a   aa  ",
"                                              aaaa           a  aaa  aaaaaa   a     aaa     a   aa  ",
"                                            aaaa           a  aaaaaaaaaaaaa    a      a      a   a  ",
"                                           aa            a   aaa  aa    a aa    a      a     a   aa ",
"                                          aaa     a     aa aa aaaa       a a    aa      a    aa  aa ",
"                                          aaa a   a     aaaaaaaaaa a             aa     a   aaa  aa ",
"                                          aa  a a a     aaaa      aaa        a   aa         aaa aaa ",
"                                          a a a a a a   aaa  a        a          aa     a   aaaaaa  ",
"                                          aaaaa a a aaaaaaa a  aa             a   a   aaaaaaaaa     ",
"                                          aaaaaaaaaaaaaaaaaaa  a  a a         aaaaaaaaaaaaa         ",
"                                           aaaaaaaaaaa  aaaa a a a aa       aaaaaa                  ",
"                                              aaa a     aaaa a a a a      aaaaa                     ",
"                                                         aaaaaaaaaaaa   aaa                         ",
"                                                           aaaaa aa  aaaa                           ",
"                                                               aaaaaaaa                             "
};


void dds_init(void);
void dds_reset(void);
void writeFreq(unsigned long in_freq);
void draw(unsigned long in_freq, int scale, int repeat);

void dds_init(void)
{
  DDRB = (1<<CLK)|(1<<FQ)|(1<<DATA)|(1<<RST);
  PORTB = (0<<CLK)|(0<<FQ)|(0<<DATA)|(0<<RST);
}

void dds_reset(void)
{
  PORTB &= ~((0<<CLK)|(0<<FQ)|(0<<DATA));

  PORTB &= ~(1<<RST);     delayMicroseconds(5);
  PORTB |= (1<<RST);      delayMicroseconds(5);
  PORTB &= ~(1<<RST);     delayMicroseconds(5);

  PORTB &= ~(1<<CLK);     delayMicroseconds(5);
  PORTB |= (1<<CLK);      delayMicroseconds(5);
  PORTB &= ~(1<<CLK);     delayMicroseconds(5);

  PORTB &= ~(1<<DATA); 

  PORTB &= ~(1<<FQ);     delayMicroseconds(5);
  PORTB |= (1<<FQ);      delayMicroseconds(5);
  PORTB &= ~(1<<FQ);
}

void writeFreq(unsigned long in_freq)
{
  unsigned long data_word = ((in_freq * 4294967296UL ) / 180000000UL); 
  boolean bits;

  PORTB |= (1<<FQ);      
  delayMicroseconds(TD);
  PORTB &= ~(1<<FQ);

  Serial.print("Set Frequency :");
  Serial.print(in_freq);
  Serial.println(" Hz");

  for(int i=0; i<32; i++)
  {
    bits = ((data_word >> i) & 0x01);
    if(bits)
      PORTB |= (1<<DATA); 
    else
      PORTB &= ~(1<<DATA); 

    delayMicroseconds(TD);
    PORTB |= (1<<CLK);      
    delayMicroseconds(TD);
    PORTB &= ~(1<<CLK);     
  }

  Serial.print(' ');

  for(int i=0; i<8; i++)
  {
    if(i<1)
      PORTB |= (1<<DATA); 
    else
      PORTB &= ~(1<<DATA); 

    delayMicroseconds(TD);
    PORTB |= (1<<CLK);      
    delayMicroseconds(TD);
    PORTB &= ~(1<<CLK);  
  }

  delayMicroseconds(TD);
  PORTB |= (1<<FQ);      
  delayMicroseconds(TD);
  PORTB &= ~(1<<FQ);

  return;
}

void drawCat(unsigned long in_freq, int scale, int repeat)
{
  char c;
  
  for(int i=CAT_HEIGHT-1;i>-1;i--)
  {
    for(int k=0;k<repeat;k++)
    {
      for(int j=0;j<CAT_WIDTH;j++)
      {
        c = pgm_read_byte(&(cat[i][j]));
        
        if(isAscii(c) && !isSpace(c) && !isWhitespace(c))
        {
          writeFreq((unsigned long)(in_freq + j*scale*400UL));
        }
        
        else if(isSpace(c) || isWhitespace(c))
        {
          writeFreq(1000);
        }
      }
    }
  }
}

void setup()
{
  Serial.begin(115200);
  Serial.print("Sketch:   "); Serial.println(__FILE__);
  Serial.print("Uploaded: "); Serial.println(__DATE__);
  Serial.println(" ");
  
  delay(2000);

  dds_init();
  dds_reset();
  writeFreq(freq);
}

void loop()
{
  //void draw(unsigned long in_freq, int scale, int repeat)
  drawCat(35000000, 2, 2);
  delay(3000);
}
