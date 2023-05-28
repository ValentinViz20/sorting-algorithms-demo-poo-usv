#pragma once

// The max size for the vectors when using the benchmark options
const int ARRAY_TO_SORT_MAX_SIZE = 20'000'000;

// The max size for the vectors when visualizing them side by side
const int ARRAY_SIZE_VISUALIZE = 50;

// The max amount of characters there can be in an 1080p full screen console window
const int MAX_LINE_LEN = 211;


// Regular colors
#define RESET   "\033[0m"
#define BLACK   "\033[30m"         /* Black */
#define RED     "\033[31m"         /* Red */
#define GREEN   "\033[32m"         /* Green */
#define YELLOW  "\033[33m"         /* Yellow */
#define BLUE    "\033[34m"         /* Blue */
#define MAGENTA "\033[35m"         /* Magenta */
#define CYAN    "\033[36m"         /* Cyan */
#define WHITE   "\033[37m"         /* White */

// Bold colors
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

#define CHAR1 char(1) // ☺
#define CHAR2 char(2) // ☻
#define CHAR3 char(3) // ♥
#define CHAR4 char(4) // ♦
#define CHAR5 char(5) // ♣
#define CHAR6 char(6) // ♠
#define CHAR10 char(10) //
#define CHAR11 char(11) // ♂
#define CHAR12 char(12) // ♀
#define CHAR14 char(14) // ♫
#define CHAR15 char(15) // ☼
#define CHAR16 char(16) // ►
#define CHAR17 char(17) // ◄
#define CHAR18 char(18) // ↕
#define CHAR19 char(19) // ‼
#define CHAR20 char(20) // ¶
#define CHAR21 char(21) // §
#define CHAR22 char(22) // ▬
#define CHAR23 char(23) // ↨
#define CHAR24 char(24) // ↑
#define CHAR25 char(25) // ↓
#define CHAR26 char(26) // →
#define CHAR28 char(28) // ∟
#define CHAR29 char(29) // ↔
#define CHAR30 char(30) // ▲
#define CHAR31 char(31) // ▼
#define CHAR33 char(33) // !
#define CHAR34 char(34) // "
#define CHAR35 char(35) // #
#define CHAR36 char(36) // $
#define CHAR37 char(37) // %
#define CHAR38 char(38) // &
#define CHAR39 char(39) // '
#define CHAR40 char(40) // (
#define CHAR41 char(41) // )
#define CHAR42 char(42) // *
#define CHAR43 char(43) // +
#define CHAR44 char(44) // ,
#define CHAR45 char(45) // -
#define CHAR46 char(46) // .
#define CHAR47 char(47) // /
#define CHAR48 char(48) // 0
#define CHAR49 char(49) // 1
#define CHAR50 char(50) // 2
#define CHAR51 char(51) // 3
#define CHAR52 char(52) // 4
#define CHAR53 char(53) // 5
#define CHAR54 char(54) // 6
#define CHAR55 char(55) // 7
#define CHAR56 char(56) // 8
#define CHAR57 char(57) // 9
#define CHAR58 char(58) // :
#define CHAR59 char(59) // ;
#define CHAR60 char(60) // <
#define CHAR61 char(61) // =
#define CHAR62 char(62) // >
#define CHAR63 char(63) // ?
#define CHAR64 char(64) // @
#define CHAR65 char(65) // A
#define CHAR66 char(66) // B
#define CHAR67 char(67) // C
#define CHAR68 char(68) // D
#define CHAR69 char(69) // E
#define CHAR70 char(70) // F
#define CHAR71 char(71) // G
#define CHAR72 char(72) // H
#define CHAR73 char(73) // I
#define CHAR74 char(74) // J
#define CHAR75 char(75) // K
#define CHAR76 char(76) // L
#define CHAR77 char(77) // M
#define CHAR78 char(78) // N
#define CHAR79 char(79) // O
#define CHAR80 char(80) // P
#define CHAR81 char(81) // Q
#define CHAR82 char(82) // R
#define CHAR83 char(83) // S
#define CHAR84 char(84) // T
#define CHAR85 char(85) // U
#define CHAR86 char(86) // V
#define CHAR87 char(87) // W
#define CHAR88 char(88) // X
#define CHAR89 char(89) // Y
#define CHAR90 char(90) // Z
#define CHAR91 char(91) // [
#define CHAR93 char(93) // ]
#define CHAR94 char(94) // ^
#define CHAR95 char(95) // _
#define CHAR96 char(96) // `
#define CHAR97 char(97) // a
#define CHAR98 char(98) // b
#define CHAR99 char(99) // c
#define CHAR100 char(100) // d
#define CHAR101 char(101) // e
#define CHAR102 char(102) // f
#define CHAR103 char(103) // g
#define CHAR104 char(104) // h
#define CHAR105 char(105) // i
#define CHAR106 char(106) // j
#define CHAR107 char(107) // k
#define CHAR108 char(108) // l
#define CHAR109 char(109) // m
#define CHAR110 char(110) // n
#define CHAR111 char(111) // o
#define CHAR112 char(112) // p
#define CHAR113 char(113) // q
#define CHAR114 char(114) // r
#define CHAR115 char(115) // s
#define CHAR116 char(116) // t
#define CHAR117 char(117) // u
#define CHAR118 char(118) // v
#define CHAR119 char(119) // w
#define CHAR120 char(120) // x
#define CHAR121 char(121) // y
#define CHAR122 char(122) // z
#define CHAR123 char(123) // {
#define CHAR124 char(124) // |
#define CHAR125 char(125) // }
#define CHAR126 char(126) // ~
#define CHAR127 char(127) // ⌂
#define CHAR128 char(128) // Ç
#define CHAR129 char(129) // ü
#define CHAR130 char(130) // é
#define CHAR131 char(131) // â
#define CHAR132 char(132) // ä
#define CHAR133 char(133) // à
#define CHAR134 char(134) // å
#define CHAR135 char(135) // ç
#define CHAR136 char(136) // ê
#define CHAR137 char(137) // ë
#define CHAR138 char(138) // è
#define CHAR139 char(139) // ï
#define CHAR140 char(140) // î
#define CHAR141 char(141) // ì
#define CHAR142 char(142) // Ä
#define CHAR143 char(143) // Å
#define CHAR144 char(144) // É
#define CHAR145 char(145) // æ
#define CHAR146 char(146) // Æ
#define CHAR147 char(147) // ô
#define CHAR148 char(148) // ö
#define CHAR149 char(149) // ò
#define CHAR150 char(150) // û
#define CHAR151 char(151) // ù
#define CHAR152 char(152) // ÿ
#define CHAR153 char(153) // Ö
#define CHAR154 char(154) // Ü
#define CHAR155 char(155) // ¢
#define CHAR156 char(156) // £
#define CHAR157 char(157) // ¥
#define CHAR158 char(158) // ₧
#define CHAR159 char(159) // ƒ
#define CHAR160 char(160) // á
#define CHAR161 char(161) // í
#define CHAR162 char(162) // ó
#define CHAR163 char(163) // ú
#define CHAR164 char(164) // ñ
#define CHAR165 char(165) // Ñ
#define CHAR166 char(166) // ª
#define CHAR167 char(167) // º
#define CHAR168 char(168) // ¿
#define CHAR169 char(169) // ⌐
#define CHAR170 char(170) // ¬
#define CHAR171 char(171) // ½
#define CHAR172 char(172) // ¼
#define CHAR173 char(173) // ¡
#define CHAR174 char(174) // «
#define CHAR175 char(175) // »
#define CHAR176 char(176) // ░
#define CHAR177 char(177) // ▒
#define CHAR178 char(178) // ▓
#define CHAR179 char(179) // │
#define CHAR180 char(180) // ┤
#define CHAR181 char(181) // ╡
#define CHAR182 char(182) // ╢
#define CHAR183 char(183) // ╖
#define CHAR184 char(184) // ╕
#define CHAR185 char(185) // ╣
#define CHAR186 char(186) // ║
#define CHAR187 char(187) // ╗
#define CHAR188 char(188) // ╝
#define CHAR189 char(189) // ╜
#define CHAR190 char(190) // ╛
#define CHAR191 char(191) // ┐
#define CHAR192 char(192) // └
#define CHAR193 char(193) // ┴
#define CHAR194 char(194) // ┬
#define CHAR195 char(195) // ├
#define CHAR196 char(196) // ─
#define CHAR197 char(197) // ┼
#define CHAR198 char(198) // ╞
#define CHAR199 char(199) // ╟
#define CHAR200 char(200) // ╚
#define CHAR201 char(201) // ╔
#define CHAR202 char(202) // ╩
#define CHAR203 char(203) // ╦
#define CHAR204 char(204) // ╠
#define CHAR205 char(205) // ═
#define CHAR206 char(206) // ╬
#define CHAR207 char(207) // ╧
#define CHAR208 char(208) // ╨
#define CHAR209 char(209) // ╤
#define CHAR210 char(210) // ╥
#define CHAR211 char(211) // ╙
#define CHAR212 char(212) // ╘
#define CHAR213 char(213) // ╒
#define CHAR214 char(214) // ╓
#define CHAR215 char(215) // ╫
#define CHAR216 char(216) // ╪
#define CHAR217 char(217) // ┘
#define CHAR218 char(218) // ┌
#define BLOCK char(219) // █
#define CHAR220 char(220) // ▄
#define CHAR221 char(221) // ▌
#define CHAR222 char(222) // ▐
#define CHAR223 char(223) // ▀
#define CHAR224 char(224) // α
#define CHAR225 char(225) // ß
#define CHAR226 char(226) // Γ
#define CHAR227 char(227) // π
#define CHAR228 char(228) // Σ
#define CHAR229 char(229) // σ
#define CHAR230 char(230) // µ
#define CHAR231 char(231) // τ
#define CHAR232 char(232) // Φ
#define CHAR233 char(233) // Θ
#define CHAR234 char(234) // Ω
#define CHAR235 char(235) // δ
#define CHAR236 char(236) // ∞
#define CHAR237 char(237) // φ
#define CHAR238 char(238) // ε
#define CHAR239 char(239) // ∩
#define CHAR240 char(240) // ≡
#define CHAR241 char(241) // ±
#define CHAR242 char(242) // ≥
#define CHAR243 char(243) // ≤
#define CHAR244 char(244) // ⌠
#define CHAR245 char(245) // ⌡
#define CHAR246 char(246) // ÷
#define CHAR247 char(247) // ≈
#define CHAR248 char(248) // °
#define CHAR249 char(249) // ∙
#define CHAR250 char(250) // ·
#define CHAR251 char(251) // √
#define CHAR252 char(252) // ⁿ
#define CHAR253 char(253) // ²
#define CHAR254 char(254) // ■