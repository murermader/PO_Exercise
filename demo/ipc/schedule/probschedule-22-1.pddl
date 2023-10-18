(define (problem schedule-22-1)
(:domain schedule)
(:objects
    W0
    V0
    U0
    S0
    R0
    P0
    Q0
    O0
    N0
    M0
    L0
    K0
    J0
    I0
    H0
    G0
    F0
    E0
    D0
    C0
    B0
    A0
 - part
    CIRCULAR
    OBLONG
 - ashape
    BLUE
    YELLOW
    RED
    BLACK
 - colour
    TWO
    THREE
    ONE
 - width
    BACK
    FRONT
 - anorient
)
(:init
    (SHAPE A0 CYLINDRICAL)
    (SURFACE-CONDITION A0 ROUGH)
    (PAINTED A0 RED)
    (HAS-HOLE A0 ONE FRONT)
    (TEMPERATURE A0 COLD)
    (SHAPE B0 CIRCULAR)
    (SURFACE-CONDITION B0 SMOOTH)
    (PAINTED B0 RED)
    (HAS-HOLE B0 THREE BACK)
    (TEMPERATURE B0 COLD)
    (SHAPE C0 CYLINDRICAL)
    (SURFACE-CONDITION C0 SMOOTH)
    (PAINTED C0 YELLOW)
    (HAS-HOLE C0 THREE BACK)
    (TEMPERATURE C0 COLD)
    (SHAPE D0 OBLONG)
    (SURFACE-CONDITION D0 POLISHED)
    (PAINTED D0 YELLOW)
    (HAS-HOLE D0 ONE FRONT)
    (TEMPERATURE D0 COLD)
    (SHAPE E0 CYLINDRICAL)
    (SURFACE-CONDITION E0 POLISHED)
    (PAINTED E0 BLACK)
    (HAS-HOLE E0 TWO BACK)
    (TEMPERATURE E0 COLD)
    (SHAPE F0 OBLONG)
    (SURFACE-CONDITION F0 SMOOTH)
    (PAINTED F0 RED)
    (HAS-HOLE F0 ONE BACK)
    (TEMPERATURE F0 COLD)
    (SHAPE G0 OBLONG)
    (SURFACE-CONDITION G0 ROUGH)
    (PAINTED G0 BLUE)
    (HAS-HOLE G0 ONE BACK)
    (TEMPERATURE G0 COLD)
    (SHAPE H0 OBLONG)
    (SURFACE-CONDITION H0 ROUGH)
    (PAINTED H0 RED)
    (HAS-HOLE H0 ONE FRONT)
    (TEMPERATURE H0 COLD)
    (SHAPE I0 CYLINDRICAL)
    (SURFACE-CONDITION I0 POLISHED)
    (PAINTED I0 BLUE)
    (HAS-HOLE I0 THREE FRONT)
    (TEMPERATURE I0 COLD)
    (SHAPE J0 CYLINDRICAL)
    (SURFACE-CONDITION J0 SMOOTH)
    (PAINTED J0 YELLOW)
    (HAS-HOLE J0 THREE FRONT)
    (TEMPERATURE J0 COLD)
    (SHAPE K0 CIRCULAR)
    (SURFACE-CONDITION K0 ROUGH)
    (PAINTED K0 YELLOW)
    (HAS-HOLE K0 ONE BACK)
    (TEMPERATURE K0 COLD)
    (SHAPE L0 CIRCULAR)
    (SURFACE-CONDITION L0 ROUGH)
    (PAINTED L0 RED)
    (HAS-HOLE L0 THREE FRONT)
    (TEMPERATURE L0 COLD)
    (SHAPE M0 CIRCULAR)
    (SURFACE-CONDITION M0 ROUGH)
    (PAINTED M0 BLACK)
    (HAS-HOLE M0 THREE BACK)
    (TEMPERATURE M0 COLD)
    (SHAPE N0 CIRCULAR)
    (SURFACE-CONDITION N0 ROUGH)
    (PAINTED N0 RED)
    (HAS-HOLE N0 ONE BACK)
    (TEMPERATURE N0 COLD)
    (SHAPE O0 OBLONG)
    (SURFACE-CONDITION O0 ROUGH)
    (PAINTED O0 RED)
    (HAS-HOLE O0 THREE FRONT)
    (TEMPERATURE O0 COLD)
    (SHAPE Q0 CYLINDRICAL)
    (SURFACE-CONDITION Q0 POLISHED)
    (PAINTED Q0 BLACK)
    (HAS-HOLE Q0 ONE FRONT)
    (TEMPERATURE Q0 COLD)
    (SHAPE P0 OBLONG)
    (SURFACE-CONDITION P0 POLISHED)
    (PAINTED P0 YELLOW)
    (HAS-HOLE P0 THREE FRONT)
    (TEMPERATURE P0 COLD)
    (SHAPE R0 OBLONG)
    (SURFACE-CONDITION R0 POLISHED)
    (PAINTED R0 YELLOW)
    (HAS-HOLE R0 THREE BACK)
    (TEMPERATURE R0 COLD)
    (SHAPE S0 CIRCULAR)
    (SURFACE-CONDITION S0 POLISHED)
    (PAINTED S0 BLUE)
    (HAS-HOLE S0 TWO BACK)
    (TEMPERATURE S0 COLD)
    (SHAPE U0 CYLINDRICAL)
    (SURFACE-CONDITION U0 ROUGH)
    (PAINTED U0 YELLOW)
    (HAS-HOLE U0 TWO FRONT)
    (TEMPERATURE U0 COLD)
    (SHAPE V0 CYLINDRICAL)
    (SURFACE-CONDITION V0 SMOOTH)
    (PAINTED V0 BLUE)
    (HAS-HOLE V0 THREE FRONT)
    (TEMPERATURE V0 COLD)
    (SHAPE W0 CYLINDRICAL)
    (SURFACE-CONDITION W0 SMOOTH)
    (PAINTED W0 BLACK)
    (HAS-HOLE W0 THREE FRONT)
    (TEMPERATURE W0 COLD)
    (CAN-ORIENT DRILL-PRESS BACK)
    (CAN-ORIENT PUNCH BACK)
    (CAN-ORIENT DRILL-PRESS FRONT)
    (CAN-ORIENT PUNCH FRONT)
    (HAS-PAINT IMMERSION-PAINTER YELLOW)
    (HAS-PAINT SPRAY-PAINTER YELLOW)
    (HAS-PAINT IMMERSION-PAINTER BLUE)
    (HAS-PAINT SPRAY-PAINTER BLUE)
    (HAS-PAINT IMMERSION-PAINTER BLACK)
    (HAS-PAINT SPRAY-PAINTER BLACK)
    (HAS-PAINT IMMERSION-PAINTER RED)
    (HAS-PAINT SPRAY-PAINTER RED)
    (HAS-BIT DRILL-PRESS THREE)
    (HAS-BIT PUNCH THREE)
    (HAS-BIT DRILL-PRESS TWO)
    (HAS-BIT PUNCH TWO)
    (HAS-BIT DRILL-PRESS ONE)
    (HAS-BIT PUNCH ONE)
)
(:goal (and
    (SHAPE M0 CYLINDRICAL)
    (PAINTED F0 BLACK)
    (SURFACE-CONDITION W0 POLISHED)
    (SURFACE-CONDITION H0 SMOOTH)
    (PAINTED L0 BLACK)
    (PAINTED E0 YELLOW)
    (PAINTED A0 BLACK)
    (SHAPE B0 CYLINDRICAL)
    (SHAPE L0 CYLINDRICAL)
    (PAINTED N0 BLACK)
    (SURFACE-CONDITION G0 SMOOTH)
    (PAINTED P0 BLUE)
    (PAINTED V0 YELLOW)
    (PAINTED R0 BLACK)
    (SHAPE N0 CYLINDRICAL)
    (SHAPE H0 CYLINDRICAL)
    (PAINTED U0 BLACK)
    (SURFACE-CONDITION M0 POLISHED)
    (PAINTED C0 RED)
    (SURFACE-CONDITION O0 SMOOTH)
    (SHAPE D0 CYLINDRICAL)
    (SHAPE K0 CYLINDRICAL)
)))
