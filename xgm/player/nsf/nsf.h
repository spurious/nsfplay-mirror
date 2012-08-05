#ifndef _NSF_H_
#define _NSF_H_
#include "../soundData.h"

#define NSF_MAX_PATH 512

namespace xgm
{
  /**
   * NSF�t�@�C���^
   */
  class NSF : public SoundDataMSP
  {
  public:
    char magic[5];
    UINT8 version;
    UINT8 songs;
    UINT8 start;
    UINT16 load_address;
    UINT16 init_address;
    UINT16 play_address;
    char filename[NSF_MAX_PATH];
    char print_title[256+64]; // margin 64 chars.
    char title_nsf[32];
    char artist_nsf[32];
    char copyright_nsf[32];
    char* title;
    char* artist;
    char* copyright;
    char* ripper; // NSFe only
    char* text; // NSFe only
    UINT16 speed_ntsc;
    UINT8 bankswitch[8];
    UINT16 speed_pal;
    UINT8 pal_ntsc;
    UINT8 soundchip;
    bool use_vrc7;
    bool use_vrc6;
    bool use_fds;
    bool use_fme7;
    bool use_mmc5;
    bool use_n106;
    UINT8 extra[4];
    UINT8 *body;
    UINT8* nsfe_image;
    int bodysize;

    /** ���ݑI�𒆂̋Ȕԍ� */
    int song;
    /** �v���C���X�g����ǂ񂾃f�[�^�Ȃ�true */
    bool playlist_mode;
    /** ���t���� */
    int time_in_ms, default_playtime;
    /** ���[�v���� */
    int loop_in_ms;
    /** �t�F�[�h���� */
    int fade_in_ms, default_fadetime;
    /** ���[�v�� */
    int loop_num, default_loopnum;
    /** ���t���Ԃ��s���̎�true�i�f�t�H���g�̉��t���Ԃ��g�p�j*/
    bool playtime_unknown;
    bool title_unknown;

      NSF ();
     ~NSF ();
    /**
     * NSF�t�@�C���̓ǂݍ���
     *
     * @param image �o�C�i���C���[�W�ւ̃|�C���^
     * @param size  �C���[�W�̃T�C�Y
     * @return ������ true ���s�� false
     */

    // loads file (playlist or NSF or NSFe)
    bool LoadFile (const char *fn);

    // loads NSF (or NSFe via LoadNSFe)
    bool Load (UINT8 * image, UINT32 size);

    // loads NSFe, if info is false INFO chunk is required to initialize
    bool LoadNSFe(UINT8* image, UINT32 size, bool info);

    void DebugOut ();
    /**
     * �^�C�g��������̎擾
     *
     * @return �^�C�g�������� (��Ȏ� - �^�C�g��)
     */
    char *GetTitleString (const char *format=NULL, int song=-1);
    char *GetPlaylistString (const char *format, bool b);
    int GetLength ();
    void SetTitleString (char *);
    void SetDefaults (int playtime, int fadetime, int loopnum);
    void SetLength (int time_in_ms);
    void SetSong (int);
    int GetSong ();
    int GetSongNum();

    int GetPlayTime ();
    int GetLoopTime ();
    int GetFadeTime ();
    int GetLoopNum ();
  };

}                               // namespace 
#endif
