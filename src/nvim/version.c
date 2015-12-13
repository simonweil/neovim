/// @file version.c
///
/// Nvim was forked from Vim 7.4.160.
/// Vim originated from Stevie version 3.6 (Fish disk 217) by GRWalter (Fred).

#include <inttypes.h>
#include <assert.h>
#include <limits.h>

#include "nvim/vim.h"
#include "nvim/ascii.h"
#include "nvim/iconv.h"
#include "nvim/version.h"
#include "nvim/charset.h"
#include "nvim/memline.h"
#include "nvim/memory.h"
#include "nvim/message.h"
#include "nvim/misc2.h"
#include "nvim/screen.h"
#include "nvim/strings.h"

// version info generated by the build system
#include "auto/versiondef.h"

#define STR_(x) #x
#define STR(x) STR_(x)

// for ":version", ":intro", and "nvim --version"
#ifndef NVIM_VERSION_MEDIUM
#define NVIM_VERSION_MEDIUM STR(NVIM_VERSION_MAJOR) "." STR(NVIM_VERSION_MINOR)\
  "." STR(NVIM_VERSION_PATCH) NVIM_VERSION_PRERELEASE
#endif
#define NVIM_VERSION_LONG "NVIM " NVIM_VERSION_MEDIUM


char *Version = VIM_VERSION_SHORT;
char *longVersion = NVIM_VERSION_LONG;
char *version_buildtype = "Build type: " NVIM_VERSION_BUILD_TYPE;
char *version_cflags = "Compilation: " NVIM_VERSION_CFLAGS;

#ifdef INCLUDE_GENERATED_DECLARATIONS
# include "version.c.generated.h"
#endif

static char *features[] = {
#ifdef HAVE_ACL
  "+acl",
#else
  "-acl",
#endif

#if (defined(HAVE_ICONV_H) && defined(USE_ICONV)) || defined(DYNAMIC_ICONV)
# ifdef DYNAMIC_ICONV
  "+iconv/dyn",
# else
  "+iconv",
# endif
#else
  "-iconv",
#endif

#ifdef HAVE_JEMALLOC
  "+jemalloc",
#else
  "-jemalloc",
#endif
  NULL
};

// clang-format off
static int included_patches[] = {
  // 1000,
  // 999 NA
  // 998,
  // 997 NA
  // 996 NA
  // 995 NA
  // 994 NA
  // 993,
  // 992 NA
  // 991,
  // 990 NA
  // 989,
  // 988 NA
  // 987 NA
  // 986 NA
  // 985 NA
  // 984,
  // 983,
  // 982,
  // 981,
  // 980,
  // 979 NA
  // 978,
  // 977,
  // 976 NA
  // 975,
  // 974,
  // 973,
  // 972,
  // 971,
  // 970,
  // 969,
  // 968,
  // 967 NA
  // 966 NA
  // 965 NA
  // 964,
  // 963,
  // 962 NA
  // 961,
  // 960 NA
  // 959 NA
  // 958,
  // 957,
  // 956,
  // 955,
  // 954 NA
  // 953,
  // 952,
  // 951,
  // 950,
  // 949,
  // 948 NA
  // 947,
  // 946,
  // 945,
  944,
  // 943,
  // 942,
  // 941,
  // 940 NA
  // 939,
  // 938 NA
  // 937,
  // 936,
  // 935,
  // 934 NA
  // 933,
  // 932,
  // 931,
  // 930 NA
  // 929,
  // 928 NA
  // 927 NA
  // 926,
  // 925,
  // 924 NA
  // 923 NA
  // 922,
  // 921 NA
  // 920 NA
  // 919 NA
  // 918 NA
  // 917 NA
  916,
  // 915,
  // 914,
  // 913 NA
  // 912,
  // 911 NA
  // 910 NA
  // 909,
  // 908 NA
  // 907 NA
  // 906 NA
  // 905,
  // 904,
  // 903,
  // 902 NA
  // 901,
  // 900 NA
  // 899 NA
  898,
  // 897,
  // 896,
  // 895,
  // 894 NA
  // 893,
  // 892,
  // 891,
  // 890 NA
  // 889,
  // 888,
  // 887,
  // 886 NA
  // 885,
  // 884 NA
  // 883,
  // 882,
  // 881,
  // 880 NA
  // 879,
  // 878,
  // 877,
  // 876 NA
  // 875 NA
  // 874 NA
  // 873,
  // 872 NA
  // 871,
  // 870,
  // 869 NA
  // 868,
  // 867 NA
  // 866,
  // 865,
  // 864 NA
  // 863 NA
  // 862 NA
  // 861 NA
  // 860,
  // 859,
  858,
  // 857,
  // 856,
  // 855 NA
  // 854 NA
  // 853,
  // 852 NA
  // 851 NA
  // 850 NA
  849,
  // 848,
  // 847,
  // 846 NA
  // 845,
  // 844,
  // 843,
  // 842 NA
  // 841 NA
  // 840 NA
  // 839,
  // 838,
  // 837 NA
  836,
  // 835,
  // 834,
  // 833,
  // 832,
  // 831,
  // 830,
  // 829 NA
  // 828,
  // 827,
  826,
  // 825,
  // 824 NA
  // 823,
  // 822,
  // 821,
  // 820,
  // 819,
  // 818,
  // 817,
  // 816,
  // 815,
  // 814,
  813,
  // 812,
  // 811,
  // 810,
  809,
  // 808 NA
  // 807,
  // 806,
  // 805,
  // 804,
  803,
  802,
  // 801,
  // 800,
  799,
  // 798,
  // 797,
  // 796 NA
  795,
  // 794 NA
  793,
  // 792,
  791,
  790,
  789,
  // 788 NA
  787,
  786,
  785,
  784,
  // 783 NA
  // 782,
  781,
  // 780 NA
  // 779,
  // 778 NA
  // 777 NA
  776,
  775,
  774,
  773,
  // 772 NA
  // 771,
  // 770 NA
  // 769,
  // 768,
  // 767,
  // 766 NA
  // 765,
  // 764,
  // 763 NA
  // 762 NA
  // 761 NA
  // 760,
  // 759 NA
  // 758,
  // 757 NA
  // 756 NA
  // 755,
  // 754,
  // 753,
  // 752,
  // 751 NA
  // 750 NA
  // 749,
  // 748,
  // 747,
  // 746,
  // 745,
  // 744 NA
  // 743,
  // 742,
  // 741,
  // 740,
  // 739,
  // 738 NA
  // 737,
  736,
  // 735,
  // 734,
  // 733,
  // 732,
  // 731 NA
  // 730 NA
  // 729,
  // 728 NA
  // 727 NA
  // 726 NA
  // 725,
  // 724 NA
  723,
  // 722,
  // 721,
  // 720 NA
  719,
  // 718,
  // 717,
  // 716,
  // 715,
  // 714,
  713,
  712,
  711,
  710,
  // 709,
  // 708,
  707,
  706,
  // 705 NA
  // 704,
  // 703 NA
  702,
  // 701 NA
  // 700,
  699,
  // 698,
  // 697,
  696,
  695,
  // 694,
  // 693,
  // 692 NA
  // 691 NA
  690,
  // 689,
  // 688,
  // 687 NA
  686,
  // 685,
  // 684,
  // 683 NA
  682,
  // 681 NA
  // 680,
  // 679 NA
  // 678 NA
  // 677 NA
  // 676 NA
  675,
  // 674 NA
  673,
  // 672,
  671,
  670,
  // 669 NA
  668,
  667,
  // 666 NA
  665,
  // 664 NA
  // 663 NA
  // 662,
  // 661 NA
  660,
  659,
  658,
  // 657 NA
  // 656,
  655,
  // 654,
  653,
  // 652 NA
  651,
  // 650 NA
  649,
  // 648 NA
  // 647 NA
  646,
  645,
  // 644 NA
  // 643,
  // 642,
  // 641 NA
  640,
  // 639,
  // 638 NA
  637,
  636,
  635,
  // 634,
  633,
  // 632 NA
  631,
  630,
  629,
  // 628 NA
  // 627 NA
  // 626 NA
  // 625 NA
  // 624 NA
  623,
  // 622 NA
  // 621 NA
  // 620 NA
  // 619 NA
  // 618 NA
  617,
  // 616,
  615,
  // 614,
  // 613,
  612,
  // 611 NA
  // 610 NA
  609,
  608,
  // 607 NA
  606,
  605,
  604,
  // 603,
  602,
  601,
  600,
  599,
  598,
  597,
  // 596 NA
  595,
  594,
  593,
  // 592 NA
  // 591 NA
  590,
  // 589 NA
  588,
  587,
  // 586 NA
  585,
  // 584 NA
  // 583 NA
  582,
  // 581 NA
  580,
  579,
  578,
  577,
  576,
  575,
  574,
  // 573,
  572,
  // 571 NA
  // 570 NA
  // 569,
  568,
  567,
  566,
  565,
  // 564 NA
  563,
  562,
  561,
  // 560 NA
  559,
  // 558 NA
  // 557 NA
  // 556 NA
  // 555 NA
  554,
  553,
  552,
  551,
  550,
  549,
  // 548 NA
  547,
  546,
  545,
  // 544 NA
  543,
  542,
  541,
  // 540 NA
  539,
  538,
  537,
  536,
  535,
  // 534 NA
  533,
  532,
  531,
  530,
  529,
  528,
  527,
  526,
  525,
  524,
  // 523 NA
  // 522 NA
  521,
  520,
  519,
  518,
  517,
  516,
  515,
  514,
  513,
  // 512 NA
  // 511 NA
  // 510 NA
  // 509 NA
  508,
  // 507 NA
  // 506 NA
  // 505 NA
  // 504 NA
  503,
  502,
  // 501 NA
  500,
  499,
  // 498 NA
  497,
  // 496 NA
  // 495 NA
  494,
  493,
  492,
  491,
  490,
  489,
  488,
  487,
  486,
  485,
  // 484 NA
  483,
  // 482 NA
  // 481 NA
  // 480 NA
  // 479 NA
  478,
  477,
  // 476 NA
  // 475 NA
  474,
  473,
  472,
  // 471 NA
  470,
  // 469 NA
  468,
  467,
  466,
  // 465 NA
  // 464 NA
  463,
  462,
  // 461 NA
  // 460 NA
  // 459 NA
  458,
  457,
  456,
  455,
  454,
  // 453 NA
  452,
  // 451 NA
  450,
  449,
  // 448 NA
  447,
  446,
  445,
  444,
  // 443 NA
  442,
  441,
  440,
  439,
  438,
  437,
  436,
  435,
  434,
  433,
  // 432 NA
  // 431 NA
  // 430 NA
  // 429 NA
  // 428 NA
  427,
  // 426 NA
  425,
  // 424 NA
  423,
  422,
  421,
  // 420 NA
  419,
  418,
  417,
  416,
  415,
  414,
  // 413 NA
  // 412 NA
  411,
  410,
  // 409 NA
  408,
  407,
  406,
  405,
  // 404 NA
  // 403 NA
  // 402 NA
  // 401 NA
  // 400 NA
  // 399 NA
  // 398 NA
  397,
  396,
  395,
  // 394 NA
  // 393 NA
  392,
  391,
  390,
  389,
  388,
  387,
  386,
  // 385 NA
  // 384 NA
  383,
  382,
  381,
  // 380 NA
  379,
  378,
  377,
  376,
  375,
  374,
  373,
  372,
  371,
  370,
  369,
  368,
  367,
  // 366 NA
  365,
  364,
  // 363 NA
  362,
  361,
  360,
  359,
  358,
  357,
  // 356 NA
  355,
  // 354 NA
  353,
  352,
  351,
  350,
  349,
  348,
  347,
  346,
  345,
  344,
  343,
  // 342 NA
  341,
  // 340 NA
  339,
  338,
  337,
  336,
  335,
  334,
  // 333 NA
  // 332 NA
  331,
  330,
  329,
  328,
  327,
  // 326 NA
  325,
  324,
  323,
  // 322 NA
  // 321 NA
  320,
  // 319 NA
  318,
  317,
  // 316 NA
  315,
  314,
  313,
  312,
  311,
  310,
  309,
  308,
  // 307 NA
  306,
  305,
  // 304 NA
  303,
  302,
  301,
  // 300 NA
  // 299 NA
  298,
  297,
  296,
  295,
  294,
  293,
  292,
  291,
  290,
  289,
  288,
  // 287 NA
  286,
  285,
  284,
  // 283 NA
  282,
  281,
  280,
  279,
  278,
  277,
  276,
  275,
  274,
  // 273 NA
  272,
  // 271 NA
  // 270 NA
  269,
  268,
  267,
  266,
  265,
  264,
  // 263 NA
  262,
  261,
  260,
  // 259 NA
  // 258 NA
  // 257 NA
  256,
  // 255 NA
  // 254 NA
  253,
  // 252 NA
  251,
  // 250 NA
  249,
  248,
  247,
  // 246 NA
  245,
  // 244,
  243,
  242,
  241,
  240,
  239,
  // 238,
  237,
  236,
  235,
  234,
  233,
  232,
  231,
  230,
  229,
  // 228 NA
  // 227 NA
  226,
  // 225 NA
  // 224 NA
  // 223 NA
  // 222 NA
  221,
  220,
  219,
  218,
  // 217 NA
  // 216 NA
  215,
  // 214 NA
  213,
  // 212 NA
  211,
  210,
  209,
  // 208 NA
  207,
  // 206 NA
  205,
  204,
  203,
  // 202 NA
  201,
  // 200 NA
  199,
  // 198 NA
  // 197 NA
  // 196 NA
  // 195 NA
  // 194 NA
  193,
  192,
  191,
  // 190 NA
  // 189 NA
  // 188 NA
  187,
  186,
  // 185 NA
  184,
  // 183 NA
  // 182 NA
  181,
  // 180 NA
  // 179 NA
  178,
  // 177 NA
  // 176 NA
  // 175 NA
  // 174 NA
  173,
  172,
  171,
  170,
  169,
  // 168 NA
  167,
  166,
  165,
  // 164 NA
  // 163 NA
  // 162 NA
  // 161 NA
  160,
  159,
  158,
  157,
  156,
  155,
  154,
  153,
  152,
  151,
  150,
  149,
  148,
  147,
  146,
  145,
  144,
  143,
  142,
  141,
  140,
  139,
  138,
  137,
  136,
  135,
  134,
  133,
  132,
  131,
  130,
  129,
  128,
  127,
  126,
  125,
  124,
  123,
  122,
  121,
  120,
  119,
  118,
  117,
  116,
  115,
  114,
  113,
  112,
  111,
  110,
  109,
  108,
  107,
  106,
  105,
  104,
  103,
  102,
  101,
  100,
  99,
  98,
  97,
  96,
  95,
  94,
  93,
  92,
  91,
  90,
  89,
  88,
  87,
  86,
  85,
  84,
  83,
  82,
  81,
  80,
  79,
  78,
  77,
  76,
  75,
  74,
  73,
  72,
  71,
  70,
  69,
  68,
  67,
  66,
  65,
  64,
  63,
  62,
  61,
  60,
  59,
  58,
  57,
  56,
  55,
  54,
  53,
  52,
  51,
  50,
  49,
  48,
  47,
  46,
  45,
  44,
  43,
  42,
  41,
  40,
  39,
  38,
  37,
  36,
  35,
  34,
  33,
  32,
  31,
  30,
  29,
  28,
  27,
  26,
  25,
  24,
  23,
  22,
  21,
  20,
  19,
  18,
  17,
  16,
  15,
  14,
  13,
  12,
  11,
  10,
  9,
  8,
  7,
  6,
  5,
  4,
  3,
  2,
  1,
  0
};
// clang-format on

/// Place to put a short description when adding a feature with a patch.
/// Keep it short, e.g.,: "relative numbers", "persistent undo".
/// Also add a comment marker to separate the lines.
/// See the official Vim patches for the diff format: It must use a context of
/// one line only.  Create it by hand or use "diff -C2" and edit the patch.
static char *(extra_patches[]) = {
  // Add your patch description below this line
  NULL
};

/// Checks whether patch `n` has been included.
///
/// @param n The patch number.
///
/// @return TRUE if patch "n" has been included.
int has_patch(int n)
{
  int i;
  for (i = 0; included_patches[i] != 0; ++i) {
    if (included_patches[i] == n) {
      return TRUE;
    }
  }
  return FALSE;
}

void ex_version(exarg_T *eap)
{
  // Ignore a ":version 9.99" command.
  if (*eap->arg == NUL) {
    msg_putchar('\n');
    list_version();
  }
}

/// List all features aligned in columns, dictionary style.
static void list_features(void)
{
  int nfeat = 0;
  int width = 0;

  // Find the length of the longest feature name, use that + 1 as the column
  // width
  int i;
  for (i = 0; features[i] != NULL; ++i) {
    int l = (int)STRLEN(features[i]);

    if (l > width) {
      width = l;
    }
    nfeat++;
  }
  width += 1;

  if (Columns < width) {
    // Not enough screen columns - show one per line
    for (i = 0; features[i] != NULL; ++i) {
      version_msg(features[i]);
      if (msg_col > 0) {
        msg_putchar('\n');
      }
    }
    return;
  }

  // The rightmost column doesn't need a separator.
  // Sacrifice it to fit in one more column if possible.
  int ncol = (int)(Columns + 1) / width;
  int nrow = nfeat / ncol + (nfeat % ncol ? 1 : 0);

  // i counts columns then rows.  idx counts rows then columns.
  for (i = 0; !got_int && i < nrow * ncol; ++i) {
    int idx = (i / ncol) + (i % ncol) * nrow;
    if (idx < nfeat) {
      int last_col = (i + 1) % ncol == 0;
      msg_puts((char_u *)features[idx]);
      if (last_col) {
        if (msg_col > 0) {
          msg_putchar('\n');
        }
      } else {
        while (msg_col % width) {
          msg_putchar(' ');
        }
      }
    } else {
      if (msg_col > 0) {
        msg_putchar('\n');
      }
    }
  }
  MSG_PUTS("For differences from Vim, see :help vim-differences\n\n");
}

void list_version(void)
{
  // When adding features here, don't forget to update the list of
  // internal variables in eval.c!
  MSG(longVersion);
  MSG(version_buildtype);
  MSG(version_cflags);

  // Print the list of extra patch descriptions if there is at least one.
  char *s = "";
  if (extra_patches[0] != NULL) {
    MSG_PUTS(_("\nExtra patches: "));
    s = "";

    for (int i = 0; extra_patches[i] != NULL; ++i) {
      MSG_PUTS(s);
      s = ", ";
      MSG_PUTS(extra_patches[i]);
    }
  }

#ifdef HAVE_PATHDEF

  if ((*compiled_user != NUL) || (*compiled_sys != NUL)) {
    MSG_PUTS(_("\nCompiled "));

    if (*compiled_user != NUL) {
      MSG_PUTS(_("by "));
      MSG_PUTS(compiled_user);
    }

    if (*compiled_sys != NUL) {
      MSG_PUTS("@");
      MSG_PUTS(compiled_sys);
    }
  }
#endif  // ifdef HAVE_PATHDEF

  version_msg(_("\n\nOptional features included (+) or not (-): "));

  list_features();

#ifdef SYS_VIMRC_FILE
  version_msg(_("   system vimrc file: \""));
  version_msg(SYS_VIMRC_FILE);
  version_msg("\"\n");
#endif  // ifdef SYS_VIMRC_FILE
#ifdef HAVE_PATHDEF

  if (*default_vim_dir != NUL) {
    version_msg(_("  fall-back for $VIM: \""));
    version_msg(default_vim_dir);
    version_msg("\"\n");
  }

  if (*default_vimruntime_dir != NUL) {
    version_msg(_(" f-b for $VIMRUNTIME: \""));
    version_msg(default_vimruntime_dir);
    version_msg("\"\n");
  }
#endif  // ifdef HAVE_PATHDEF
}

/// Output a string for the version message.  If it's going to wrap, output a
/// newline, unless the message is too long to fit on the screen anyway.
///
/// @param s
static void version_msg(char *s)
{
  int len = (int)STRLEN(s);

  if (!got_int
      && (len < (int)Columns)
      && (msg_col + len >= (int)Columns)
      && (*s != '\n')) {
    msg_putchar('\n');
  }

  if (!got_int) {
    MSG_PUTS(s);
  }
}


/// Show the intro message when not editing a file.
void maybe_intro_message(void)
{
  if (bufempty()
      && (curbuf->b_fname == NULL)
      && (firstwin->w_next == NULL)
      && (vim_strchr(p_shm, SHM_INTRO) == NULL)) {
    intro_message(FALSE);
  }
}

/// Give an introductory message about Vim.
/// Only used when starting Vim on an empty file, without a file name.
/// Or with the ":intro" command (for Sven :-).
///
/// @param colon TRUE for ":intro"
void intro_message(int colon)
{
  int i;
  long row;
  long blanklines;
  int sponsor;
  char *p;
  static char *(lines[]) = {
    N_(NVIM_VERSION_LONG),
    "",
    N_("by Bram Moolenaar et al."),
    N_("Vim is open source and freely distributable"),
    "",
    N_("First time using a vi-like editor?"),
    N_("Type :Tutor<Enter> to get started!"),
    "",
    N_("Already know your way around Vim?"),
    N_("See :help nvim-intro for an introduction to Neovim."),
    "",
    N_("Still have questions?"),
    N_("Reach out to the Neovim community at neovim.io/community."),
    "",
    N_("Help poor children in Uganda!"),
    N_("type  :help iccf<Enter>       for information "),
    "",
    N_("type  :q<Enter>               to exit         "),
    N_("type  :help<Enter>  or  <F1>  for on-line help"),
    N_("type  :help nvim<Enter>       for Neovim help "),
  };

  // blanklines = screen height - # message lines
  size_t lines_size = ARRAY_SIZE(lines);
  assert(lines_size <= LONG_MAX);

  blanklines = Rows - ((long)lines_size - 1l);

  // Don't overwrite a statusline.  Depends on 'cmdheight'.
  if (p_ls > 1) {
    blanklines -= Rows - topframe->fr_height;
  }

  if (blanklines < 0) {
    blanklines = 0;
  }

  // Show the sponsor and register message one out of four times, the Uganda
  // message two out of four times.
  sponsor = (int)time(NULL);
  sponsor = ((sponsor & 2) == 0) - ((sponsor & 4) == 0);

  // start displaying the message lines after half of the blank lines
  row = blanklines / 2;

  if (((row >= 2) && (Columns >= 50)) || colon) {
    for (i = 0; i < (int)ARRAY_SIZE(lines); ++i) {
      p = lines[i];

      if (sponsor != 0) {
        if (strstr(p, "children") != NULL) {
          p = sponsor < 0
              ? N_("Sponsor Vim development!")
              : N_("Become a registered Vim user!");
        } else if (strstr(p, "iccf") != NULL) {
          p = sponsor < 0
              ? N_("type  :help sponsor<Enter>    for information ")
              : N_("type  :help register<Enter>   for information ");
        } else if (strstr(p, "Orphans") != NULL) {
          p = N_("menu  Help->Sponsor/Register  for information    ");
        }
      }

      if (*p != NUL) {
        do_intro_line(row, (char_u *)_(p), 0);
      }
      row++;
    }
  }

  // Make the wait-return message appear just below the text.
  if (colon) {
    assert(row <= INT_MAX);
    msg_row = (int)row;
  }
}

static void do_intro_line(long row, char_u *mesg, int attr)
{
  long col;
  char_u *p;
  int l;
  int clen;

  // Center the message horizontally.
  col = vim_strsize(mesg);

  col = (Columns - col) / 2;

  if (col < 0) {
    col = 0;
  }

  // Split up in parts to highlight <> items differently.
  for (p = mesg; *p != NUL; p += l) {
    clen = 0;

    for (l = 0; p[l] != NUL
         && (l == 0 || (p[l] != '<' && p[l - 1] != '>')); ++l) {
      if (has_mbyte) {
        clen += ptr2cells(p + l);
        l += (*mb_ptr2len)(p + l) - 1;
      } else {
        clen += byte2cells(p[l]);
      }
    }
    assert(row <= INT_MAX && col <= INT_MAX);
    screen_puts_len(p, l, (int)row, (int)col, *p == '<' ? hl_attr(HLF_8) : attr);
    col += clen;
  }
}

/// ":intro": clear screen, display intro screen and wait for return.
///
/// @param eap
void ex_intro(exarg_T *eap)
{
  screenclear();
  intro_message(TRUE);
  wait_return(TRUE);
}
