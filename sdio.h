/*
 * sd.h
 *
 *  Created on: Jun 10, 2010
 *      Author: andi
 */

#ifndef SD_H_
#define SD_H_

class SDIO
{
public:
	SDIO();

private:
	void init();
	void select( bool enCS);
	bool card_available();
};

#endif /* SD_H_ */
