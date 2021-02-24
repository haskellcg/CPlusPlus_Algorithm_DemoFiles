/**************************************************************************
 * author: haskellcg
 * date: 2021-02-24
 * description: computational geometry utility functions
 *************************************************************************/

#include <math.h>
#include "computational_geometry_utils.h"

double get_radian_from_a_to_b(double dAStartX, double dAStartY, double dAEndX, double dAEndY,
                              double dBStartX, double dBStartY, double dBEndX, double dBEndY)
{
    double dRadianFromAToX = atan2(dAEndY - dAStartY, dAEndX - dAStartX);
    double dRadianFromBToX = atan2(dBEndY - dBStartY, dBEndX - dBStartX);
    return (dRadianFromAToX - dRadianFromBToX);
}

void computational_geometry_utils_test()
{
    print_highlight_msg(">>> Test computational geometry utility functions:\n");
    print_normal_msg("vector A: (0, 0, 10, 10)\n");
    print_normal_msg("vector B: (0, 0, 10, -10)\n");
    double dRadianFromAToB = get_radian_from_a_to_b(0, 0, 10, 10,
                                                    0, 0, 10, -10);
    if (abs(dRadianFromAToB - (PI / 2)) < 1E-7){
        print_correct_msg("radian from vector A to B is correct\n");
    } else {
        print_error_msg("radian from vector A to B is wrong\n");
    }
}
