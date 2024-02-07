#ifndef __FLOWSENS__
#define __FLOWSENS__

#include "../Sensor/Sensor.h"
#include "../../types.h"

class FlowSensor : public Sensor{
public: 
    FlowSensor();

    void begin();
    void read();
    //int16 getCached();

private: 
    int8 pin;
    //int16 cachedPosition;
    // lookup table scaled * 1000
    int16 flowLookup[1024] = {500, 501, 502, 504, 505, 507, 508, 510, 512, 513, 515, 516, 518, 519, 521, 523, 524, 526, 527, 529, 531, 532, 534, 536, 537, 539, 541, 543, 544, 546, 548, 550, 551, 553, 555, 557, 558, 560, 562, 564, 566, 568, 570, 571, 573, 575, 577, 579, 581, 583, 585, 587, 589, 591, 593, 595, 597, 599, 601, 603, 605, 607, 609, 611, 613, 615, 617, 619, 621, 623, 626, 628, 630, 632, 634, 636, 639, 641, 643, 645, 647, 650, 652, 654, 656, 659, 661, 663, 666, 668, 670, 672, 675, 677, 680, 682, 684, 687, 689, 691, 694, 696, 699, 701, 704, 706, 709, 711, 714, 716, 719, 721, 724, 726, 729, 731, 734, 736, 739, 742, 744, 747, 749, 752, 755, 757, 760, 763, 765, 768, 771, 774, 776, 779, 782, 785, 787, 790, 793, 796, 798, 801, 804, 807, 810, 813, 815, 818, 821, 824, 827, 830, 833, 836, 839, 842, 845, 847, 850, 853, 856, 859, 862, 865, 868, 872, 875, 878, 881, 884, 887, 890, 893, 896, 899, 902, 906, 909, 912, 915, 918, 921, 925, 928, 931, 934, 938, 941, 944, 947, 951, 954, 957, 960, 964, 967, 970, 974, 977, 980, 984, 987, 991, 994, 997, 1001, 1004, 1008, 1011, 1015, 1018, 1022, 1025, 1029, 1032, 1036, 1039, 1043, 1046, 1050, 1053, 1057, 1060, 1064, 1068, 1071, 1075, 1079, 1082, 1086, 1089, 1093, 1097, 1101, 1104, 1108, 1112, 1115, 1119, 1123, 1127, 1130, 1134, 1138, 1142, 1146, 1149, 1153, 1157, 1161, 1165, 1169, 1172, 1176, 1180, 1184, 1188, 1192, 1196, 1200, 1204, 1208, 1212, 1216, 1220, 1224, 1228, 1232, 1236, 1240, 1244, 1248, 1252, 1256, 1260, 1264, 1268, 1272, 1276, 1280, 1285, 1289, 1293, 1297, 1301, 1305, 1310, 1314, 1318, 1322, 1327, 1331, 1335, 1339, 1344, 1348, 1352, 1356, 1361, 1365, 1369, 1374, 1378, 1382, 1387, 1391, 1396, 1400, 1404, 1409, 1413, 1418, 1422, 1427, 1431, 1435, 1440, 1444, 1449, 1453, 1458, 1462, 1467, 1472, 1476, 1481, 1485, 1490, 1494, 1499, 1504, 1508, 1513, 1518, 1522, 1527, 1532, 1536, 1541, 1546, 1550, 1555, 1560, 1565, 1569, 1574, 1579, 1584, 1588, 1593, 1598, 1603, 1608, 1612, 1617, 1622, 1627, 1632, 1637, 1642, 1647, 1651, 1656, 1661, 1666, 1671, 1676, 1681, 1686, 1691, 1696, 1701, 1706, 1711, 1716, 1721, 1726, 1731, 1736, 1741, 1747, 1752, 1757, 1762, 1767, 1772, 1777, 1782, 1788, 1793, 1798, 1803, 1808, 1814, 1819, 1824, 1829, 1835, 1840, 1845, 1850, 1856, 1861, 1866, 1872, 1877, 1882, 1888, 1893, 1898, 1904, 1909, 1915, 1920, 1925, 1931, 1936, 1942, 1947, 1953, 1958, 1964, 1969, 1975, 1980, 1986, 1991, 1997, 2002, 2008, 2013, 2019, 2025, 2030, 2036, 2041, 2047, 2053, 2058, 2064, 2070, 2075, 2081, 2087, 2092, 2098, 2104, 2110, 2115, 2121, 2127, 2133, 2138, 2144, 2150, 2156, 2162, 2167, 2173, 2179, 2185, 2191, 2197, 2203, 2208, 2214, 2220, 2226, 2232, 2238, 2244, 2250, 2256, 2262, 2268, 2274, 2280, 2286, 2292, 2298, 2304, 2310, 2316, 2322, 2328, 2334, 2341, 2347, 2353, 2359, 2365, 2371, 2377, 2384, 2390, 2396, 2402, 2408, 2415, 2421, 2427, 2433, 2440, 2446, 2452, 2458, 2465, 2471, 2477, 2484, 2490, 2496, 2503, 2509, 2515, 2522, 2528, 2535, 2541, 2547, 2554, 2560, 2567, 2573, 2580, 2586, 2593, 2599, 2606, 2612, 2619, 2625, 2632, 2638, 2645, 2651, 2658, 2665, 2671, 2678, 2684, 2691, 2698, 2704, 2711, 2718, 2724, 2731, 2738, 2744, 2751, 2758, 2765, 2771, 2778, 2785, 2792, 2798, 2805, 2812, 2819, 2826, 2833, 2839, 2846, 2853, 2860, 2867, 2874, 2881, 2888, 2894, 2901, 2908, 2915, 2922, 2929, 2936, 2943, 2950, 2957, 2964, 2971, 2978, 2985, 2992, 2999, 3006, 3014, 3021, 3028, 3035, 3042, 3049, 3056, 3063, 3071, 3078, 3085, 3092, 3099, 3106, 3114, 3121, 3128, 3135, 3143, 3150, 3157, 3164, 3172, 3179, 3186, 3194, 3201, 3208, 3216, 3223, 3230, 3238, 3245, 3253, 3260, 3267, 3275, 3282, 3290, 3297, 3305, 3312, 3320, 3327, 3335, 3342, 3350, 3357, 3365, 3372, 3380, 3387, 3395, 3402, 3410, 3418, 3425, 3433, 3441, 3448, 3456, 3463, 3471, 3479, 3487, 3494, 3502, 3510, 3517, 3525, 3533, 3541, 3548, 3556, 3564, 3572, 3580, 3587, 3595, 3603, 3611, 3619, 3627, 3634, 3642, 3650, 3658, 3666, 3674, 3682, 3690, 3698, 3706, 3714, 3722, 3730, 3738, 3746, 3754, 3762, 3770, 3778, 3786, 3794, 3802, 3810, 3818, 3826, 3834, 3843, 3851, 3859, 3867, 3875, 3883, 3891, 3900, 3908, 3916, 3924, 3933, 3941, 3949, 3957, 3966, 3974, 3982, 3990, 3999, 4007, 4015, 4024, 4032, 4040, 4049, 4057, 4065, 4074, 4082, 4091, 4099, 4107, 4116, 4124, 4133, 4141, 4150, 4158, 4167, 4175, 4184, 4192, 4201, 4209, 4218, 4226, 4235, 4244, 4252, 4261, 4269, 4278, 4287, 4295, 4304, 4313, 4321, 4330, 4339, 4347, 4356, 4365, 4373, 4382, 4391, 4400, 4408, 4417, 4426, 4435, 4444, 4452, 4461, 4470, 4479, 4488, 4497, 4505, 4514, 4523, 4532, 4541, 4550, 4559, 4568, 4577, 4586, 4595, 4604, 4613, 4622, 4631, 4640, 4649, 4658, 4667, 4676, 4685, 4694, 4703, 4712, 4721, 4730, 4739, 4748, 4758, 4767, 4776, 4785, 4794, 4803, 4813, 4822, 4831, 4840, 4849, 4859, 4868, 4877, 4887, 4896, 4905, 4914, 4924, 4933, 4942, 4952, 4961, 4970, 4980, 4989, 4998, 5008, 5017, 5027, 5036, 5046, 5055, 5064, 5074, 5083, 5093, 5102, 5112, 5121, 5131, 5140, 5150, 5159, 5169, 5179, 5188, 5198, 5207, 5217, 5227, 5236, 5246, 5255, 5265, 5275, 5284, 5294, 5304, 5313, 5323, 5333, 5343, 5352, 5362, 5372, 5382, 5391, 5401, 5411, 5421, 5431, 5440, 5450, 5460, 5470, 5480, 5490, 5500, 5509, 5519, 5529, 5539, 5549, 5559, 5569, 5579, 5589, 5599, 5609, 5619, 5629, 5639, 5649, 5659, 5669, 5679, 5689, 5699, 5709, 5719, 5729, 5740, 5750, 5760, 5770, 5780, 5790, 5800, 5811, 5821, 5831, 5841, 5851, 5862, 5872, 5882, 5892, 5903, 5913, 5923, 5933, 5944, 5954, 5964, 5975, 5985, 5995, 6006, 6016, 6026, 6037, 6047, 6058, 6068, 6078, 6089, 6099, 6110, 6120, 6131, 6141, 6152, 6162, 6173, 6183, 6194, 6204, 6215, 6225, 6236, 6247, 6257, 6268, 6278, 6289, 6300, 6310, 6321, 6332, 6342, 6353, 6364, 6374, 6385, 6396, 6406, 6417, 6428, 6439, 6449, 6460, 6471, 6482, 6493, 6503, 6514, 6525, 6536, 6547, 6557, 6568, 6579, 6590, 6601, 6612, 6623, 6634, 6645, 6656, 6667, 6678, 6688, 6699, 6710, 6721, 6732, 6743, 6755, 6766, 6777, 6788, 6799, 6810, 6821, 6832, 6843, 6854, 6865, 6876, 6888, 6899, 6910, 6921, 6932, 6943, 6955, 6966, 6977, 6988, 7000};
    
    int16 bitsToFlowRate(uint16 bits);
}
#endif