#include "battery.h"

void battert_calculator(int16_t &bav, float &vout, float &vcc, int8_t &percent) 
{
    bav = analogRead(A0);
    vout = bav * 5.0 / 1024;
    /* Thevenin - Norton chia áp R1 = 10k - R2 = 2k2 */
    /* vcc = vout * 12k2 / 2k2 */
    vcc = vout * 12200.0 / 2200;                /* calculator battery voltage */
    percent = vcc / 3.8 * 100;
    if (percent > 100) percent = 100;           /* calculator battery percent */

}
