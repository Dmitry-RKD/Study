/*
 * C1.c
 * 
 * Copyright 2025 Дмитрий <Дмитрий@DESKTOP-V4T7I45>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * don't_panic
nick_is_a_mastodon
T0G0gx1HHH94tAAEG1tA8E4Y6OLJVI05aB713hDCCN363sCuteeKY5yh2O1F0As5BH6lfOaJbPjIQAZV87DpyhRbVG4kgXRKWDE7C1EL4EA4dBDC3LHQF9Kj
9UD6J6fM4HT0G0gx1HHH94tAAEG1tA8E4Y6OLJVI05aB713hDCCN363sCuteeKY5yh2O1F0As5BH6lfOaJbPjIQAZV87DpyhRbVG

ieuGrARfL0T44K4JHIIP2B0FiSUNPQ1SBVzZPiediFAlzuQLUDsqZ3W7eumMbtzFBnlP2mUFf2S1rg5Fc1BEWKsa9cwVVZ7LapA2F4CyzR8Gl1VhZMew8tPYvs21dfoNMyFrlK4FWAAzj3119TmYHRX6YI40b19XeEBRyk95JuwdS53mW4Us94OAoBt7CXXL3IcNlDAB
foNMyFrlK4FWAAzj3119TmYHRX6YI40b19XeEBRyk95JuwdS53mW4Us94OAoBt7CXXL3IcNlDAB2MDKWLYUWpA6vDB7ND3J952BUS2R1uW341skTJZGbWFpM5N6RxgBh5po6MbGX2EyRZW29iNKPMmRfTaRWKwkbWiXI8xMQPfq4p3mieuGrARfL0T44K4JHIIP2B0FiSUNPQ1SBVzZPiediFAlzuQLUDsqZ3W7eumMbtzFBnlP2mUFf2S
 */


#include <stdio.h>
#include <string.h>

int main() {
    char str1[10001];
    char str2[10001];

    fgets(str1, sizeof(str1), stdin);
    fgets(str2, sizeof(str2), stdin);

    str1[strcspn(str1, "\n")] = 0;
    str2[strcspn(str2, "\n")] = 0;

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int pref_suff = 0; 
    int suff_pref = 0; 

	 for (int len = 1; len <= len1 && len <= len2; len++) 
    {
		int temp = 1;
		for (int i = 0; i < len; i++) 
		{
			if (str1[i] != str2[len2 - len + i]) 
			{
			temp = 0;
			break;
			}
		}
		if (temp) 
		{
			pref_suff = len;
		}
	}

	for (int len = 1; len <= len1 && len <= len2; len++) 
	{
		int temp = 1;
		for (int i = 0; i < len; i++)
		{
            if (str1[len1 - len + i] != str2[i]) 
            {
                temp = 0;
                break;
            }
        }
		if (temp) 
			suff_pref = len;
    }
    printf("%d %d\n", pref_suff, suff_pref);

    return 0;
}

