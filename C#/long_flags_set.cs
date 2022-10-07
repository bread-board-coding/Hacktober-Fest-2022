using System;
using System.Collections.Generic;

/*
	Optimized implementation to store bitwise flags
	of a set larger than 64 entries (C# ulong enum limitation)
*/
public class FlagBucket
{
    private readonly Dictionary<int, ulong> flags;
    
    public FlagBucket()
    {
        flags = new Dictionary<int, ulong>();
    }
    
    public void Set(int flag)
    {        
        int key = (int)Math.Floor(flag / 64f);

        if (!flags.ContainsKey(key))
        {
            flags.Add(key, 0);
        }

        int localIdx = flag % 64;
        flags[key] |= 1ul << localIdx;
    }

    public void Remove(int flag)
    {
        int key = (int)Math.Floor(flag / 64f);

        if (!flags.ContainsKey(key))
        {
            return;
        }

        int localIdx = flag % 64;
        flags[key] &= ~(1ul << localIdx);
    }

    public bool IsSet(int flag)
    {
        int key = (int)Math.Floor(flag / 64f);

        if (!flags.ContainsKey(key))
        {
            return false;
        }

        ulong shiftedLocalIdx = 1ul << (flag % 64);
        return (flags[key] & shiftedLocalIdx) == shiftedLocalIdx;
    }
}