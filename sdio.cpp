/*
 * sdmc.cpp
 *
 *  Created on: Jun 10, 2010
 *      Author: andi
 */

#include <wiring.h>
#include "sdio.h"

#define PIN_NCS  	10
#define PIN_SCK		13
#define PIN_MOSI	11
#define PIN_MISO	12


SDIO::SDIO() {
	pinMode( PIN_NCS, OUTPUT);
	pinMode( PIN_MOSI, OUTPUT);
	pinMode( PIN_MISO, INPUT);
	pinMode( PIN_SCK, OUTPUT);

	init();
}

void SDIO::init() {
	select( false);

    /* initialize SPI with lowest frequency; max. 400kHz during identification mode of card */
    SPCR = (0 << SPIE) | /* SPI Interrupt Enable */
           (1 << SPE)  | /* SPI Enable */
           (0 << DORD) | /* Data Order: MSB first */
           (1 << MSTR) | /* Master mode */
           (0 << CPOL) | /* Clock Polarity: SCK low when idle */
           (0 << CPHA) | /* Clock Phase: sample on rising SCK edge */
           (1 << SPR1) | /* Clock Frequency: f_OSC / 128 */
           (1 << SPR0);
    SPSR &= ~(1 << SPI2X); /* No doubled clock frequency */

    delay( 200);
}

void SDIO::select( bool enCS) {
	digitalWrite( PIN_NCS, (enCS) ? LOW : HIGH);
}

bool SDIO::card_available() {
	// TODO: read card_available pin
	return true;
}
