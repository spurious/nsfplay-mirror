#ifndef _COUNTER_H_
#define _COUNTER_H_
#include "../../xtypes.h"

namespace xgm
{
  // �N���b�N�ƍĐ����[�g�̍����z���\�ȃJ�E���^
  class Counter
  {
  protected:
    int COUNTER_SHIFT;
    double ratio;
    UINT32 val, next, step, max;

  public:
      Counter ()
    {
      COUNTER_SHIFT = 24;
      val = 0;
      step = 0;
    }

     ~Counter ()
    {
    }

    // clk  : �{����inc/dec�Ăяo�����g��
    // rate : ���̃J�E���^�𗘗p������ۂ̎��g��
    // m : �J�E���^�̍ő�l(���̒l�𒴂���ƃt���OON)
    void init (double clk, double rate, UINT32 m)
    {
      ratio = (1 << COUNTER_SHIFT) * (clk / rate);
      step = (UINT32) ratio;
      max = m << COUNTER_SHIFT;
      val = 0;
    }

    void setshift (int cs)
    {
      COUNTER_SHIFT = cs;
    }

    void setstep (UINT32 s)
    {
      step = (UINT32)(ratio * s);
    }

    void stop ()
    {
      step = 0;
    }

    void setmax (UINT32 m)
    {
      max = m << COUNTER_SHIFT;
      if (val > max)
        val = max;
    }

    void reset (UINT32 v)
    {
      val = v;
    }

    // s : ���̃R�[���ł̑����̋t�� -- �����䃌�W�X�^�̒l
    void setcycle (UINT32 s)
    {
      step = (UINT32)(ratio / (s + 1));
    }

    void load (UINT32 i)
    {
      next = val = (i << COUNTER_SHIFT);
    }

    void reload ()
    {
      val = next;
    }

    void latch (UINT32 i)
    {
      next = val = (i << COUNTER_SHIFT);
    }

    bool down ()                // Return true and stop when it is overflowed.
    {
      if (val <= step)
      {
        val = 0;
        return true;
      }
      else
      {
        val -= step;
        return false;
      }
    }

    bool idown ()               // Return true when it is overflowed.
    {
      if (val <= step)
      {
        val = max + val - step;
        return true;
      }
      else
      {
        val -= step;
        return false;
      }
    }

    bool up ()                  // Return true and stop when it is overflowed.
    {
      if (val + step >= max)
      {
        val = max - 1;
        return true;
      }
      else
      {
        val += step;
        return false;
      }
    }

    int iup_wofc() // iup with overflow counter
    {
      int c;

      if(val+step >= max)
      {
        c = (step - (max-val))/max + 1;
        val = (val+step)%max;
        return c;
      }
      else
      {
          val += step;
          return 0;
      }
    }

    bool iup ()                 // Return true when it is overflowed.
    {
      if (val + step >= max)
      {
        val = val + step - max;
        return true;
      }
      else
      {
        val += step;
        return false;
      }
    }

    UINT32 value ()
    {
      return val >> COUNTER_SHIFT;
    }

    bool isZero ()
    {
      return (val == 0);
    }

    void print ()
    {
      printf ("(%d,%d)\n", val, step);
    }

  };

}

#endif
