// Basic MD_AD9833 test file
//
// Initialises the device to default conditions
// 
// Connect a pot to A0 to change the frequency by turning the pot
//
#include <MD_AD9833.h>
#include <SPI.h>

// Pins for SPI comm with the AD9833 IC
#define DATA  13	///< SPI Data pin number
#define CLK   14	///< SPI Clock pin number
#define FSYNC 15	///< SPI Load pin number (FSYNC in AD9833 usage)

//MD_AD9833	AD(FSYNC);  // Hardware SPI
MD_AD9833	AD(DATA, CLK, FSYNC); // Arbitrary SPI pins

void setup(void)
{
	AD.begin();
 AD.setMode (MD_AD9833::MODE_SQUARE1);
 AD.setFrequency(MD_AD9833::CHAN_0, 100);
 delay(3000);
  AD.setFrequency(MD_AD9833::CHAN_0, 500);
   delay(3000);
  AD.setFrequency(MD_AD9833::CHAN_0, 1000);
  delay(3000);
  AD.setFrequency(MD_AD9833::CHAN_0, 3000);
}

void loop(void)
{
	
	
		
}
