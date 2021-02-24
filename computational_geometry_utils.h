/**************************************************************************
 * author: haskellcg
 * date: 2021-02-24
 * description: computational geometry utility functions
 *************************************************************************/

#ifndef __COMPUTATIONAL_GEOMETRY_UTILS_H__
#define __COMPUTATIONAL_GEOMETRY_UTILS_H__

#include "common_types.h"

/**
 * @brief get radian from vector a to b
 * @param double dAStartX, A.Start.X
 * @param double dAStartY, A.Start.Y
 * @param double dAEndX, A.End.X
 * @param double dAEndY, A.End.Y
 * @param double dBStartX, B.Start.X
 * @param double dBStartY, B.Start.Y
 * @param double dBEndX, B.End.X
 * @param double dBEndY, B.End.Y
 */
double get_radian_from_a_to_b(double dAStartX, double dAStartY, double dAEndX, double dAEndY,
                              double dBStartX, double dBStartY, double dBEndX, double dBEndY);

/**
 * @brief test computational geometry utils functions
 * @param
 * @return void
 * @remarks
 */
void computational_geometry_utils_test();

#endif // __COMPUTATIONAL_GEOMETRY_UTILS_H__
