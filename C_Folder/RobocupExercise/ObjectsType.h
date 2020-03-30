#pragma once

/*Reference name OF Objsets*/
enum ObjectsName {
    OBJECT_BALL,             /*!< Ball                     */
    OBJECT_GOAL_L,           /*!< Left goal                */    // 2 goals
    OBJECT_GOAL_R,           /*!< Right goal               */
    OBJECT_LINE_L,           /*!< Left line                */    // 4 lines
    OBJECT_LINE_R,           /*!< Right line               */
    OBJECT_LINE_B,           /*!< Bottom line              */
    OBJECT_LINE_T,           /*!< Top line                 */
    OBJECT_FLAG_L_T,         /*!< Flag left top            */   // 53 flags
    OBJECT_FLAG_T_L_50,      /*!< Flag top left 50         */
    OBJECT_FLAG_T_L_40,      /*!< Flag top left 40         */
    OBJECT_FLAG_T_L_30,      /*!< Flag top left 30         */
    OBJECT_FLAG_T_L_20,      /*!< Flag top left 20         */
    OBJECT_FLAG_T_L_10,      /*!< Flag top left 10         */
    OBJECT_FLAG_T_0,         /*!< Flag top left 0          */
    OBJECT_FLAG_C_T,         /*!< Flag top center          */
    OBJECT_FLAG_T_R_10,      /*!< Flag top right 10        */
    OBJECT_FLAG_T_R_20,      /*!< Flag top right 20        */
    OBJECT_FLAG_T_R_30,      /*!< Flag top right 30        */
    OBJECT_FLAG_T_R_40,      /*!< Flag top right 40        */
    OBJECT_FLAG_T_R_50,      /*!< Flag top right 50        */
    OBJECT_FLAG_R_T,         /*!< Flag right top           */
    OBJECT_FLAG_R_T_30,      /*!< Flag right top 30        */
    OBJECT_FLAG_R_T_20,      /*!< Flag right top 20        */
    OBJECT_FLAG_R_T_10,      /*!< Flag right top 10        */
    OBJECT_FLAG_G_R_T,       /*!< Flag goal right top      */
    OBJECT_FLAG_R_0,         /*!< Flag right 0             */
    OBJECT_FLAG_G_R_B,       /*!< Flag goal right bottom   */
    OBJECT_FLAG_R_B_10,      /*!< Flag right bottom 10     */
    OBJECT_FLAG_R_B_20,      /*!< Flag right bottom 20     */
    OBJECT_FLAG_R_B_30,      /*!< Flag right bottom 30     */
    OBJECT_FLAG_R_B,         /*!< Flag right bottom        */
    OBJECT_FLAG_B_R_50,      /*!< Flag bottom right 50     */
    OBJECT_FLAG_B_R_40,      /*!< Flag bottom right 40     */
    OBJECT_FLAG_B_R_30,      /*!< Flag bottom right 30     */
    OBJECT_FLAG_B_R_20,      /*!< Flag bottom right 20     */
    OBJECT_FLAG_B_R_10,      /*!< Flag bottom right 10     */
    OBJECT_FLAG_C_B,         /*!< Flag center bottom       */
    OBJECT_FLAG_B_0,         /*!< Flag bottom 0            */
    OBJECT_FLAG_B_L_10,      /*!< Flag bottom left 10      */
    OBJECT_FLAG_B_L_20,      /*!< Flag bottom left 20      */
    OBJECT_FLAG_B_L_30,      /*!< Flag bottom left 30      */
    OBJECT_FLAG_B_L_40,      /*!< Flag bottom left 40      */
    OBJECT_FLAG_B_L_50,      /*!< Flag bottom left 50      */
    OBJECT_FLAG_L_B,         /*!< Flag left bottom         */
    OBJECT_FLAG_L_B_30,      /*!< Flag left bottom 30      */
    OBJECT_FLAG_L_B_20,      /*!< Flag left bottom 20      */
    OBJECT_FLAG_L_B_10,      /*!< Flag left bottom 10      */
    OBJECT_FLAG_G_L_B,       /*!< Flag goal left bottom    */
    OBJECT_FLAG_L_0,         /*!< Flag left 0              */
    OBJECT_FLAG_G_L_T,       /*!< Flag goal left top       */
    OBJECT_FLAG_L_T_10,      /*!< Flag left bottom 10      */
    OBJECT_FLAG_L_T_20,      /*!< Flag left bottom 20      */
    OBJECT_FLAG_L_T_30,      /*!< Flag left bottom 30      */
    OBJECT_FLAG_P_L_T,       /*!< Flag penaly left top     */
    OBJECT_FLAG_P_L_C,       /*!< Flag penaly left center  */
    OBJECT_FLAG_P_L_B,       /*!< Flag penaly left bottom  */
    OBJECT_FLAG_P_R_T,       /*!< Flag penaly right top    */
    OBJECT_FLAG_P_R_C,       /*!< Flag penaly right center */
    OBJECT_FLAG_P_R_B,       /*!< Flag penaly right bottom */
    OBJECT_FLAG_C,           /*!< Flag center field        */
    OBJECT_TEAMMATE_1,       /*!< Teammate nr 1            */    // teammates 61
    OBJECT_TEAMMATE_2,       /*!< Teammate nr 2            */
    OBJECT_TEAMMATE_3,       /*!< Teammate nr 3            */
    OBJECT_TEAMMATE_4,       /*!< Teammate nr 4            */
    OBJECT_TEAMMATE_5,       /*!< Teammate nr 5            */
    OBJECT_TEAMMATE_6,       /*!< Teammate nr 6            */
    OBJECT_TEAMMATE_7,       /*!< Teammate nr 7            */
    OBJECT_TEAMMATE_8,       /*!< Teammate nr 8            */
    OBJECT_TEAMMATE_9,       /*!< Teammate nr 9            */
    OBJECT_TEAMMATE_10,      /*!< Teammate nr 10           */
    OBJECT_TEAMMATE_11,      /*!< Teammate nr 11           */
    OBJECT_OPPONENT_1,       /*!< Opponent nr 1            */    // opponents 73
    OBJECT_OPPONENT_2,       /*!< Opponent nr 2            */
    OBJECT_OPPONENT_3,       /*!< Opponent nr 3            */
    OBJECT_OPPONENT_4,       /*!< Opponent nr 4            */
    OBJECT_OPPONENT_5,       /*!< Opponent nr 5            */
    OBJECT_OPPONENT_6,       /*!< Opponent nr 6            */
    OBJECT_OPPONENT_7,       /*!< Opponent nr 7            */
    OBJECT_OPPONENT_8,       /*!< Opponent nr 8            */
    OBJECT_OPPONENT_9,       /*!< Opponent nr 9            */
    OBJECT_OPPONENT_10,      /*!< Opponent nr 10           */
    OBJECT_OPPONENT_11,      /*!< Opponent nr 11           */
};