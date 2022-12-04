#define _GLIBCXX_USE_CXX11_ABI 0
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#pragma region input
const string input = "2991\n"
"13880\n"
"13279\n"
"1514\n"
"9507\n"
"\n"
"6544\n"
"9672\n"
"13044\n"
"4794\n"
"6648\n"
"8669\n"
"\n"
"2790\n"
"1196\n"
"3619\n"
"1692\n"
"8727\n"
"2342\n"
"1099\n"
"6083\n"
"3834\n"
"2008\n"
"\n"
"2974\n"
"4393\n"
"1146\n"
"4240\n"
"1880\n"
"3226\n"
"2390\n"
"5640\n"
"2768\n"
"1887\n"
"4217\n"
"3314\n"
"5653\n"
"2609\n"
"\n"
"4473\n"
"7306\n"
"7909\n"
"6862\n"
"7413\n"
"3738\n"
"2102\n"
"4269\n"
"5966\n"
"7491\n"
"4851\n"
"\n"
"10396\n"
"24686\n"
"9258\n"
"\n"
"1299\n"
"8539\n"
"7570\n"
"4888\n"
"2209\n"
"2720\n"
"9275\n"
"4843\n"
"1884\n"
"\n"
"2421\n"
"1872\n"
"4696\n"
"14627\n"
"7944\n"
"\n"
"28659\n"
"27933\n"
"\n"
"3477\n"
"3702\n"
"9649\n"
"3433\n"
"3288\n"
"5779\n"
"3578\n"
"5744\n"
"\n"
"14516\n"
"18228\n"
"6351\n"
"\n"
"23055\n"
"35889\n"
"\n"
"1539\n"
"8880\n"
"10443\n"
"10688\n"
"13205\n"
"\n"
"1723\n"
"10526\n"
"5505\n"
"6148\n"
"7407\n"
"1316\n"
"1386\n"
"1908\n"
"\n"
"6350\n"
"3394\n"
"1405\n"
"12681\n"
"12249\n"
"3342\n"
"\n"
"3273\n"
"4478\n"
"1674\n"
"3077\n"
"3210\n"
"4848\n"
"5194\n"
"6226\n"
"1793\n"
"6392\n"
"2969\n"
"3370\n"
"6749\n"
"\n"
"5323\n"
"3818\n"
"11179\n"
"5699\n"
"7426\n"
"2055\n"
"\n"
"7592\n"
"4222\n"
"1308\n"
"3898\n"
"1905\n"
"5747\n"
"3736\n"
"8450\n"
"4093\n"
"5432\n"
"\n"
"3650\n"
"4915\n"
"1762\n"
"1643\n"
"2548\n"
"5160\n"
"5841\n"
"3552\n"
"2407\n"
"3754\n"
"1112\n"
"2095\n"
"4010\n"
"\n"
"4648\n"
"4784\n"
"7355\n"
"6149\n"
"3842\n"
"5997\n"
"9033\n"
"8125\n"
"2140\n"
"\n"
"5701\n"
"8717\n"
"5937\n"
"1369\n"
"2407\n"
"7081\n"
"5603\n"
"8224\n"
"1719\n"
"\n"
"7134\n"
"18703\n"
"12905\n"
"9024\n"
"\n"
"1136\n"
"4968\n"
"7603\n"
"1796\n"
"6299\n"
"4692\n"
"7288\n"
"5035\n"
"6056\n"
"4214\n"
"2163\n"
"\n"
"5102\n"
"5785\n"
"2014\n"
"5626\n"
"1185\n"
"5211\n"
"5093\n"
"1674\n"
"1129\n"
"2135\n"
"5578\n"
"3682\n"
"2592\n"
"1177\n"
"\n"
"14148\n"
"6970\n"
"3442\n"
"4661\n"
"10454\n"
"\n"
"7239\n"
"17068\n"
"20869\n"
"\n"
"1314\n"
"13042\n"
"11732\n"
"3313\n"
"\n"
"16316\n"
"36536\n"
"\n"
"11462\n"
"18906\n"
"22733\n"
"\n"
"5842\n"
"1252\n"
"2089\n"
"6507\n"
"5646\n"
"3539\n"
"1135\n"
"3911\n"
"3312\n"
"3864\n"
"1561\n"
"1242\n"
"1577\n"
"4928\n"
"\n"
"6484\n"
"4452\n"
"7637\n"
"4278\n"
"3223\n"
"2596\n"
"6958\n"
"2926\n"
"8398\n"
"7834\n"
"\n"
"42277\n"
"\n"
"35666\n"
"23962\n"
"\n"
"66631\n"
"\n"
"8607\n"
"12209\n"
"12140\n"
"7439\n"
"8233\n"
"10780\n"
"\n"
"1955\n"
"4179\n"
"3115\n"
"2461\n"
"4052\n"
"1965\n"
"4867\n"
"2999\n"
"4667\n"
"6305\n"
"2033\n"
"2156\n"
"2720\n"
"5333\n"
"\n"
"7146\n"
"4223\n"
"7494\n"
"2463\n"
"9438\n"
"3799\n"
"5983\n"
"8810\n"
"5352\n"
"\n"
"6644\n"
"6079\n"
"3698\n"
"5011\n"
"8830\n"
"7311\n"
"5775\n"
"1636\n"
"\n"
"47417\n"
"\n"
"3449\n"
"4886\n"
"5862\n"
"1067\n"
"6451\n"
"6165\n"
"6269\n"
"4526\n"
"2145\n"
"3366\n"
"2907\n"
"6100\n"
"3448\n"
"1254\n"
"\n"
"5486\n"
"6003\n"
"2304\n"
"4297\n"
"4993\n"
"4572\n"
"1397\n"
"3608\n"
"1043\n"
"5773\n"
"2267\n"
"2790\n"
"3298\n"
"5842\n"
"\n"
"12417\n"
"4128\n"
"10779\n"
"13809\n"
"4455\n"
"12524\n"
"\n"
"4907\n"
"9170\n"
"2300\n"
"4787\n"
"10507\n"
"3252\n"
"3017\n"
"\n"
"5847\n"
"1655\n"
"3274\n"
"1333\n"
"1345\n"
"2974\n"
"1634\n"
"5984\n"
"2632\n"
"3336\n"
"3129\n"
"5976\n"
"4261\n"
"5377\n"
"2356\n"
"\n"
"3298\n"
"4185\n"
"18840\n"
"8294\n"
"\n"
"1545\n"
"9312\n"
"1986\n"
"7355\n"
"4092\n"
"2450\n"
"5827\n"
"9291\n"
"\n"
"15323\n"
"11402\n"
"12265\n"
"11203\n"
"10405\n"
"\n"
"6310\n"
"7512\n"
"3485\n"
"1855\n"
"5631\n"
"5606\n"
"6932\n"
"5481\n"
"2700\n"
"\n"
"1586\n"
"4820\n"
"9274\n"
"8570\n"
"1569\n"
"3103\n"
"8255\n"
"9864\n"
"\n"
"11002\n"
"2245\n"
"10309\n"
"4417\n"
"14403\n"
"\n"
"3846\n"
"6671\n"
"4086\n"
"9903\n"
"3295\n"
"8426\n"
"4783\n"
"10343\n"
"\n"
"3839\n"
"2967\n"
"4060\n"
"5648\n"
"2220\n"
"2952\n"
"5233\n"
"5410\n"
"5957\n"
"1267\n"
"5465\n"
"5686\n"
"1843\n"
"5608\n"
"2876\n"
"\n"
"1869\n"
"3328\n"
"5657\n"
"1292\n"
"2594\n"
"6721\n"
"6816\n"
"6180\n"
"3233\n"
"5446\n"
"1196\n"
"1126\n"
"6370\n"
"\n"
"7221\n"
"5771\n"
"1747\n"
"2178\n"
"2489\n"
"2483\n"
"8006\n"
"1297\n"
"7288\n"
"2882\n"
"\n"
"5109\n"
"3769\n"
"1916\n"
"4030\n"
"5064\n"
"5091\n"
"2593\n"
"4580\n"
"4883\n"
"3898\n"
"5093\n"
"1462\n"
"4974\n"
"3315\n"
"4750\n"
"\n"
"4338\n"
"8285\n"
"1073\n"
"1188\n"
"7465\n"
"6912\n"
"1933\n"
"9366\n"
"\n"
"10301\n"
"6604\n"
"3170\n"
"7569\n"
"2109\n"
"2540\n"
"1869\n"
"\n"
"8537\n"
"9525\n"
"6440\n"
"6314\n"
"7522\n"
"7153\n"
"3792\n"
"4998\n"
"8585\n"
"\n"
"2261\n"
"5367\n"
"3569\n"
"1653\n"
"5889\n"
"2656\n"
"4559\n"
"4336\n"
"4047\n"
"2517\n"
"3163\n"
"3464\n"
"5707\n"
"4080\n"
"2922\n"
"\n"
"31484\n"
"\n"
"6284\n"
"6371\n"
"3846\n"
"6099\n"
"2447\n"
"4024\n"
"6457\n"
"2455\n"
"5285\n"
"1982\n"
"1048\n"
"6029\n"
"3168\n"
"4278\n"
"\n"
"4284\n"
"4379\n"
"4699\n"
"5393\n"
"3491\n"
"4928\n"
"2769\n"
"4853\n"
"3575\n"
"5178\n"
"2761\n"
"5158\n"
"5662\n"
"3138\n"
"\n"
"9471\n"
"3142\n"
"2990\n"
"2640\n"
"5344\n"
"4397\n"
"8037\n"
"9150\n"
"2463\n"
"\n"
"3333\n"
"12379\n"
"1140\n"
"6496\n"
"12356\n"
"10438\n"
"\n"
"31049\n"
"\n"
"6280\n"
"6924\n"
"4580\n"
"5774\n"
"1092\n"
"1987\n"
"5513\n"
"1612\n"
"3775\n"
"6117\n"
"2074\n"
"1008\n"
"2792\n"
"\n"
"5978\n"
"34312\n"
"\n"
"15983\n"
"7271\n"
"10111\n"
"10061\n"
"1913\n"
"\n"
"28704\n"
"15277\n"
"\n"
"24025\n"
"23191\n"
"\n"
"18306\n"
"6711\n"
"18537\n"
"19324\n"
"\n"
"6021\n"
"4008\n"
"7214\n"
"3499\n"
"3902\n"
"4954\n"
"2579\n"
"3091\n"
"3229\n"
"5659\n"
"4769\n"
"\n"
"8220\n"
"7006\n"
"8314\n"
"12372\n"
"4550\n"
"8244\n"
"\n"
"3551\n"
"2389\n"
"6163\n"
"5021\n"
"1132\n"
"4774\n"
"1359\n"
"4387\n"
"3766\n"
"5954\n"
"3018\n"
"2230\n"
"1420\n"
"4371\n"
"\n"
"9525\n"
"9526\n"
"3372\n"
"1658\n"
"3881\n"
"6444\n"
"4351\n"
"3509\n"
"1460\n"
"\n"
"8558\n"
"7212\n"
"6909\n"
"10144\n"
"\n"
"18406\n"
"15594\n"
"\n"
"2874\n"
"5110\n"
"3416\n"
"3843\n"
"4867\n"
"2379\n"
"5323\n"
"3126\n"
"2865\n"
"1438\n"
"5739\n"
"5554\n"
"2414\n"
"2554\n"
"\n"
"4077\n"
"2048\n"
"5488\n"
"2691\n"
"5089\n"
"2188\n"
"3358\n"
"1680\n"
"2924\n"
"3096\n"
"2104\n"
"1717\n"
"1833\n"
"3019\n"
"\n"
"11757\n"
"4441\n"
"7469\n"
"3234\n"
"4779\n"
"8291\n"
"\n"
"1996\n"
"4223\n"
"4867\n"
"3717\n"
"5649\n"
"2668\n"
"5702\n"
"5023\n"
"3901\n"
"4406\n"
"5510\n"
"2661\n"
"1533\n"
"4191\n"
"1400\n"
"\n"
"7414\n"
"1109\n"
"3430\n"
"1863\n"
"5904\n"
"7684\n"
"3006\n"
"6861\n"
"2151\n"
"\n"
"5424\n"
"1766\n"
"3046\n"
"1493\n"
"2287\n"
"2836\n"
"1791\n"
"3799\n"
"3946\n"
"6174\n"
"5000\n"
"1012\n"
"1078\n"
"1054\n"
"\n"
"6378\n"
"4060\n"
"24317\n"
"\n"
"3422\n"
"8186\n"
"10230\n"
"5610\n"
"5148\n"
"5640\n"
"6697\n"
"9931\n"
"\n"
"4186\n"
"1561\n"
"5054\n"
"1160\n"
"9066\n"
"1801\n"
"3083\n"
"1458\n"
"6963\n"
"\n"
"8939\n"
"7912\n"
"8916\n"
"2111\n"
"5217\n"
"5919\n"
"5273\n"
"7538\n"
"7372\n"
"\n"
"10768\n"
"1651\n"
"7043\n"
"1197\n"
"10657\n"
"3884\n"
"4463\n"
"4241\n"
"\n"
"66810\n"
"\n"
"19272\n"
"18102\n"
"10613\n"
"3908\n"
"\n"
"4643\n"
"10608\n"
"9358\n"
"4072\n"
"8940\n"
"6360\n"
"10068\n"
"2116\n"
"\n"
"4791\n"
"5553\n"
"4483\n"
"5580\n"
"4445\n"
"3405\n"
"2528\n"
"4133\n"
"5431\n"
"4930\n"
"3270\n"
"5119\n"
"3100\n"
"\n"
"10323\n"
"6834\n"
"9322\n"
"5292\n"
"3729\n"
"10536\n"
"\n"
"4377\n"
"5696\n"
"1831\n"
"2483\n"
"2420\n"
"1045\n"
"1142\n"
"5294\n"
"3178\n"
"4678\n"
"5912\n"
"4389\n"
"2517\n"
"5257\n"
"3008\n"
"\n"
"4125\n"
"10399\n"
"11897\n"
"1295\n"
"2459\n"
"13275\n"
"\n"
"33112\n"
"5382\n"
"\n"
"4577\n"
"5342\n"
"1546\n"
"3935\n"
"2972\n"
"5917\n"
"6807\n"
"7051\n"
"7018\n"
"4855\n"
"2378\n"
"3974\n"
"\n"
"6943\n"
"3464\n"
"4843\n"
"5073\n"
"1477\n"
"8054\n"
"6873\n"
"3861\n"
"4184\n"
"7438\n"
"6297\n"
"\n"
"5298\n"
"2153\n"
"4410\n"
"4572\n"
"4580\n"
"6756\n"
"7076\n"
"1043\n"
"4894\n"
"7722\n"
"\n"
"6214\n"
"2109\n"
"3696\n"
"1819\n"
"1287\n"
"3928\n"
"1233\n"
"6297\n"
"5185\n"
"1864\n"
"3200\n"
"3230\n"
"6227\n"
"2079\n"
"\n"
"1536\n"
"3380\n"
"1856\n"
"1853\n"
"4504\n"
"4101\n"
"1167\n"
"5046\n"
"3233\n"
"2522\n"
"2409\n"
"4679\n"
"5718\n"
"1044\n"
"5828\n"
"\n"
"2824\n"
"3323\n"
"5732\n"
"1716\n"
"4082\n"
"1812\n"
"6451\n"
"5249\n"
"4976\n"
"6125\n"
"1353\n"
"5689\n"
"6242\n"
"\n"
"1084\n"
"8644\n"
"6344\n"
"3049\n"
"4275\n"
"6275\n"
"3450\n"
"5792\n"
"2225\n"
"2435\n"
"\n"
"3099\n"
"5018\n"
"4117\n"
"4452\n"
"10756\n"
"7422\n"
"3595\n"
"5963\n"
"\n"
"6311\n"
"3908\n"
"6596\n"
"3238\n"
"5050\n"
"8033\n"
"1455\n"
"6736\n"
"5930\n"
"1928\n"
"3276\n"
"\n"
"1600\n"
"1073\n"
"4772\n"
"9737\n"
"9139\n"
"8601\n"
"\n"
"4916\n"
"3294\n"
"3356\n"
"2203\n"
"2782\n"
"1691\n"
"3605\n"
"1710\n"
"1499\n"
"4469\n"
"4907\n"
"3151\n"
"2876\n"
"4872\n"
"5376\n"
"\n"
"9746\n"
"4484\n"
"6726\n"
"6405\n"
"6379\n"
"6695\n"
"1546\n"
"6393\n"
"\n"
"6285\n"
"2133\n"
"7112\n"
"2655\n"
"3135\n"
"4494\n"
"4720\n"
"2529\n"
"5476\n"
"6704\n"
"\n"
"9199\n"
"10093\n"
"11924\n"
"13132\n"
"10969\n"
"8021\n"
"\n"
"2266\n"
"6407\n"
"4116\n"
"3708\n"
"8866\n"
"8118\n"
"8493\n"
"6382\n"
"6414\n"
"\n"
"14026\n"
"15738\n"
"11978\n"
"16047\n"
"4103\n"
"\n"
"3333\n"
"2774\n"
"3092\n"
"7997\n"
"3844\n"
"7916\n"
"5528\n"
"6319\n"
"2317\n"
"4643\n"
"\n"
"19739\n"
"3748\n"
"5424\n"
"\n"
"1039\n"
"3224\n"
"2868\n"
"6107\n"
"6976\n"
"8538\n"
"6323\n"
"\n"
"16161\n"
"2927\n"
"8366\n"
"11738\n"
"7602\n"
"\n"
"1370\n"
"2592\n"
"2054\n"
"5152\n"
"3537\n"
"5643\n"
"5293\n"
"6632\n"
"1418\n"
"4779\n"
"2883\n"
"6204\n"
"\n"
"10644\n"
"12434\n"
"12655\n"
"12592\n"
"2494\n"
"\n"
"3389\n"
"2619\n"
"6847\n"
"4510\n"
"5306\n"
"5385\n"
"\n"
"1832\n"
"4541\n"
"10862\n"
"\n"
"7395\n"
"2103\n"
"3849\n"
"7964\n"
"5105\n"
"3605\n"
"7695\n"
"4921\n"
"3646\n"
"2566\n"
"5996\n"
"\n"
"3025\n"
"10709\n"
"6811\n"
"9451\n"
"1852\n"
"2736\n"
"\n"
"4548\n"
"6752\n"
"5880\n"
"2428\n"
"6486\n"
"5284\n"
"5820\n"
"\n"
"6206\n"
"1977\n"
"6271\n"
"1565\n"
"2363\n"
"6084\n"
"1943\n"
"5714\n"
"4644\n"
"4032\n"
"1643\n"
"2156\n"
"4055\n"
"4567\n"
"\n"
"5165\n"
"5035\n"
"7605\n"
"4427\n"
"2647\n"
"8011\n"
"2908\n"
"1168\n"
"3266\n"
"5529\n"
"7711\n"
"\n"
"23833\n"
"10619\n"
"15010\n"
"\n"
"5060\n"
"4907\n"
"6624\n"
"5395\n"
"1016\n"
"6929\n"
"5380\n"
"3764\n"
"5532\n"
"7831\n"
"5329\n"
"\n"
"7904\n"
"2841\n"
"1018\n"
"1426\n"
"4579\n"
"4510\n"
"3989\n"
"1289\n"
"8273\n"
"4279\n"
"\n"
"12736\n"
"14190\n"
"16883\n"
"\n"
"32835\n"
"\n"
"4317\n"
"1193\n"
"5184\n"
"4546\n"
"1694\n"
"1196\n"
"4373\n"
"2347\n"
"4049\n"
"5666\n"
"5698\n"
"2817\n"
"4678\n"
"3980\n"
"\n"
"22571\n"
"5504\n"
"\n"
"37209\n"
"\n"
"4757\n"
"4579\n"
"6807\n"
"1442\n"
"1536\n"
"6602\n"
"3905\n"
"6884\n"
"7226\n"
"3101\n"
"1120\n"
"3849\n"
"\n"
"5590\n"
"4892\n"
"3081\n"
"2536\n"
"6082\n"
"1532\n"
"2318\n"
"2777\n"
"3641\n"
"2864\n"
"2505\n"
"1679\n"
"4880\n"
"1163\n"
"2077\n"
"\n"
"3948\n"
"3128\n"
"3485\n"
"1641\n"
"3989\n"
"5132\n"
"6057\n"
"5384\n"
"5990\n"
"6257\n"
"6507\n"
"3405\n"
"3960\n"
"3868\n"
"\n"
"2939\n"
"3711\n"
"5743\n"
"3425\n"
"5965\n"
"5620\n"
"3055\n"
"6930\n"
"4500\n"
"4733\n"
"4011\n"
"1553\n"
"\n"
"8219\n"
"20157\n"
"\n"
"10494\n"
"6572\n"
"2011\n"
"4950\n"
"7388\n"
"4958\n"
"6701\n"
"10093\n"
"\n"
"5062\n"
"6365\n"
"2966\n"
"4770\n"
"6178\n"
"4993\n"
"5128\n"
"1438\n"
"6268\n"
"5552\n"
"3329\n"
"3863\n"
"4256\n"
"3647\n"
"\n"
"1580\n"
"2151\n"
"4323\n"
"2744\n"
"2838\n"
"2084\n"
"2356\n"
"2912\n"
"5797\n"
"5836\n"
"6001\n"
"6283\n"
"6956\n"
"\n"
"5872\n"
"5366\n"
"1071\n"
"3423\n"
"7950\n"
"5515\n"
"7606\n"
"4833\n"
"4363\n"
"6754\n"
"\n"
"7304\n"
"2085\n"
"2765\n"
"3046\n"
"5378\n"
"7258\n"
"3930\n"
"2047\n"
"5211\n"
"5948\n"
"3480\n"
"\n"
"9663\n"
"6108\n"
"7148\n"
"9800\n"
"10254\n"
"9203\n"
"7937\n"
"\n"
"12218\n"
"9139\n"
"13622\n"
"7696\n"
"10329\n"
"11172\n"
"\n"
"9401\n"
"9897\n"
"10143\n"
"6100\n"
"9964\n"
"2154\n"
"7319\n"
"7498\n"
"\n"
"8780\n"
"5117\n"
"7036\n"
"3037\n"
"1706\n"
"5242\n"
"7249\n"
"7284\n"
"2078\n"
"1728\n"
"\n"
"17577\n"
"7230\n"
"10234\n"
"18936\n"
"\n"
"8416\n"
"1185\n"
"2396\n"
"6979\n"
"2992\n"
"2253\n"
"2917\n"
"7305\n"
"8488\n"
"4622\n"
"\n"
"6685\n"
"5299\n"
"4251\n"
"2549\n"
"3790\n"
"5368\n"
"7221\n"
"5706\n"
"7925\n"
"6502\n"
"7808\n"
"\n"
"6241\n"
"4351\n"
"7552\n"
"3775\n"
"6773\n"
"7225\n"
"7567\n"
"5820\n"
"\n"
"3950\n"
"3540\n"
"1080\n"
"7325\n"
"3394\n"
"4633\n"
"1869\n"
"6327\n"
"3902\n"
"1421\n"
"3541\n"
"7361\n"
"\n"
"4850\n"
"7359\n"
"5156\n"
"9779\n"
"3045\n"
"3741\n"
"1889\n"
"4935\n"
"\n"
"3506\n"
"3235\n"
"2392\n"
"2384\n"
"1722\n"
"1272\n"
"1297\n"
"3784\n"
"1520\n"
"4136\n"
"4597\n"
"6208\n"
"\n"
"1713\n"
"1735\n"
"6325\n"
"7553\n"
"1611\n"
"5346\n"
"5266\n"
"1007\n"
"5645\n"
"\n"
"22956\n"
"18090\n"
"2717\n"
"\n"
"1498\n"
"8912\n"
"2860\n"
"10065\n"
"4102\n"
"10195\n"
"8619\n"
"7174\n"
"\n"
"2990\n"
"3208\n"
"7040\n"
"14050\n"
"1387\n"
"\n"
"3086\n"
"10540\n"
"8999\n"
"2483\n"
"\n"
"16011\n"
"14905\n"
"5517\n"
"9267\n"
"9327\n"
"\n"
"7848\n"
"1954\n"
"10323\n"
"7195\n"
"9807\n"
"4464\n"
"3234\n"
"2104\n"
"\n"
"2235\n"
"4964\n"
"3309\n"
"2177\n"
"5222\n"
"4738\n"
"2714\n"
"5281\n"
"3441\n"
"4456\n"
"4352\n"
"1169\n"
"2808\n"
"3138\n"
"3274\n"
"\n"
"8877\n"
"9811\n"
"5627\n"
"6382\n"
"7521\n"
"5837\n"
"\n"
"5504\n"
"4031\n"
"6402\n"
"3441\n"
"6483\n"
"5283\n"
"1036\n"
"1335\n"
"5285\n"
"4683\n"
"5401\n"
"7344\n"
"\n"
"4169\n"
"14771\n"
"1896\n"
"13377\n"
"\n"
"6438\n"
"3297\n"
"7216\n"
"5522\n"
"1471\n"
"2817\n"
"5369\n"
"6477\n"
"3806\n"
"6599\n"
"5724\n"
"6522\n"
"\n"
"6076\n"
"3239\n"
"8915\n"
"8080\n"
"2812\n"
"\n"
"1607\n"
"5198\n"
"5896\n"
"3895\n"
"1229\n"
"2030\n"
"5527\n"
"4837\n"
"5821\n"
"3149\n"
"3159\n"
"1656\n"
"6030\n"
"2010\n"
"4604\n"
"\n"
"2844\n"
"4604\n"
"5741\n"
"11440\n"
"5163\n"
"4355\n"
"\n"
"1844\n"
"5763\n"
"4911\n"
"2989\n"
"5267\n"
"6645\n"
"4968\n"
"4317\n"
"3036\n"
"1724\n"
"1784\n"
"5800\n"
"\n"
"13575\n"
"4117\n"
"4728\n"
"5783\n"
"9013\n"
"13240\n"
"\n"
"13842\n"
"15191\n"
"3141\n"
"4765\n"
"\n"
"7938\n"
"2898\n"
"7974\n"
"2035\n"
"7803\n"
"1909\n"
"1098\n"
"9097\n"
"9291\n"
"\n"
"6535\n"
"1174\n"
"4794\n"
"1525\n"
"5808\n"
"7345\n"
"2768\n"
"7255\n"
"2257\n"
"5602\n"
"\n"
"13575\n"
"19965\n"
"17232\n"
"2750\n"
"\n"
"35642\n"
"\n"
"7697\n"
"6719\n"
"1812\n"
"13584\n"
"\n"
"26437\n"
"\n"
"7606\n"
"7892\n"
"7526\n"
"4920\n"
"6775\n"
"2129\n"
"2548\n"
"7524\n"
"5114\n"
"5294\n"
"\n"
"4056\n"
"17673\n"
"13062\n"
"14865\n"
"\n"
"1487\n"
"4138\n"
"2188\n"
"3584\n"
"5151\n"
"4029\n"
"7213\n"
"2313\n"
"3330\n"
"5396\n"
"4269\n"
"\n"
"6793\n"
"7201\n"
"7619\n"
"9344\n"
"9472\n"
"5835\n"
"2234\n"
"2088\n"
"8763\n"
"\n"
"1631\n"
"2291\n"
"7526\n"
"1090\n"
"1009\n"
"5730\n"
"1354\n"
"6865\n"
"7140\n"
"6000\n"
"3380\n"
"\n"
"10624\n"
"17641\n"
"2161\n"
"\n"
"8172\n"
"8971\n"
"2217\n"
"6300\n"
"2777\n"
"6061\n"
"4855\n"
"1749\n"
"1893\n"
"\n"
"2178\n"
"8240\n"
"8476\n"
"2192\n"
"9511\n"
"8940\n"
"8280\n"
"4132\n"
"5311\n"
"\n"
"27950\n"
"33583\n"
"\n"
"2652\n"
"4372\n"
"6853\n"
"1967\n"
"6620\n"
"4484\n"
"3223\n"
"4281\n"
"5273\n"
"1766\n"
"6234\n"
"5574\n"
"\n"
"6828\n"
"5915\n"
"3458\n"
"6806\n"
"2814\n"
"4145\n"
"8642\n"
"5397\n"
"2549\n"
"7984\n"
"\n"
"6032\n"
"5403\n"
"3959\n"
"5411\n"
"4179\n"
"5540\n"
"1545\n"
"4430\n"
"2484\n"
"1772\n"
"3279\n"
"5560\n"
"1907\n"
"2885\n"
"\n"
"4832\n"
"1221\n"
"4133\n"
"1614\n"
"2348\n"
"1641\n"
"6835\n"
"6891\n"
"4221\n"
"2430\n"
"3820\n"
"2499\n"
"\n"
"5998\n"
"4269\n"
"3322\n"
"1257\n"
"7604\n"
"3261\n"
"8784\n"
"5152\n"
"6059\n"
"\n"
"9655\n"
"3995\n"
"13638\n"
"4250\n"
"2830\n"
"11687\n"
"\n"
"6156\n"
"1364\n"
"2380\n"
"2225\n"
"9824\n"
"1512\n"
"6378\n"
"6675\n"
"\n"
"1571\n"
"6937\n"
"5199\n"
"1593\n"
"4612\n"
"2487\n"
"5548\n"
"2038\n"
"2591\n"
"6347\n"
"3044\n"
"1079\n"
"4688\n"
"\n"
"5238\n"
"7304\n"
"4476\n"
"2930\n"
"3782\n"
"7293\n"
"3726\n"
"1404\n"
"1901\n"
"4445\n"
"7015\n"
"6752\n"
"\n"
"8419\n"
"\n"
"6892\n"
"6548\n"
"2671\n"
"1757\n"
"4123\n"
"3463\n"
"2570\n"
"7263\n"
"5229\n"
"5192\n"
"7325\n"
"\n"
"13782\n"
"7314\n"
"12677\n"
"12477\n"
"13486\n"
"5230\n"
"\n"
"13577\n"
"3934\n"
"10077\n"
"9166\n"
"4717\n"
"7645\n"
"\n"
"5358\n"
"2198\n"
"3312\n"
"4801\n"
"2527\n"
"4034\n"
"1999\n"
"4764\n"
"5788\n"
"3458\n"
"2843\n"
"4598\n"
"2322\n"
"2422\n"
"4872\n"
"\n"
"3140\n"
"1599\n"
"1635\n"
"8875\n"
"9163\n"
"4841\n"
"10028\n"
"5565\n"
"\n"
"2464\n"
"3454\n"
"3594\n"
"9524\n"
"8722\n"
"5689\n"
"1560\n"
"5812\n"
"3010\n"
"\n"
"6702\n"
"15704\n"
"22334\n"
"\n"
"8121\n"
"3272\n"
"8232\n"
"4521\n"
"7689\n"
"8203\n"
"3491\n"
"8651\n"
"8999\n"
"\n"
"1659\n"
"6794\n"
"8706\n"
"8685\n"
"9729\n"
"2422\n"
"7210\n"
"10240\n"
"\n"
"25308\n"
"12582\n"
"13844\n"
"\n"
"5243\n"
"5754\n"
"4904\n"
"3074\n"
"2228\n"
"2314\n"
"6750\n"
"8273\n"
"7456\n"
"\n"
"31763\n"
"33698\n"
"\n"
"11467\n"
"\n"
"1057\n"
"1163\n"
"5868\n"
"7365\n"
"6298\n"
"5522\n"
"5083\n"
"2607\n"
"2640\n"
"6784\n"
"7421\n"
"3097\n"
"\n"
"1671\n"
"6274\n"
"3342\n"
"7291\n"
"1221\n"
"7314\n"
"3739\n"
"4931\n"
"3184\n"
"4064\n"
"2119\n"
"1381\n"
"\n"
"5228\n"
"10244\n"
"8153\n"
"11913\n"
"10240\n"
"12109\n"
"10580\n"
"\n"
"61792\n"
"\n"
"10208\n"
"4324\n"
"5583\n"
"11389\n"
"9223\n"
"\n"
"4904\n"
"6100\n"
"5521\n"
"1951\n"
"14505\n"
"\n"
"2267\n"
"13080\n"
"14058\n"
"7587\n"
"11313\n"
"\n"
"5089\n"
"3437\n"
"2229\n"
"4505\n"
"6358\n"
"7240\n"
"7977\n"
"4973\n"
"1308\n"
"6776\n"
"2254\n"
"\n"
"7189\n"
"5182\n"
"\n"
"2620\n"
"2814\n"
"3095\n"
"4199\n"
"1173\n"
"2148\n"
"1367\n"
"6002\n"
"5100\n"
"6194\n"
"3338\n"
"1169\n"
"4422\n"
"1599\n"
"\n"
"2098\n"
"3218\n"
"3992\n"
"3373\n"
"7069\n"
"4080\n"
"6550\n"
"4385\n"
"5412\n"
"4140\n"
"\n"
"7124\n"
"2473\n"
"6789\n"
"1286\n"
"7079\n"
"4559\n"
"1459\n"
"6747\n"
"3849\n"
"5240\n"
"3090\n"
"2784\n"
"\n"
"17116\n"
"18851\n"
"22020\n"
"\n"
"6834\n"
"3351\n"
"3681\n"
"2709\n"
"4499\n"
"5769\n"
"7705\n"
"5554\n"
"4324\n"
"5470\n"
"5946\n"
"\n"
"1775\n"
"7411\n"
"4045\n"
"7449\n"
"1652\n"
"5962\n"
"7406\n"
"1113\n"
"6763\n"
"6892\n"
"4421\n"
"1151\n"
"\n"
"3725\n"
"6326\n"
"1296\n"
"5944\n"
"1223\n"
"1111\n"
"4446\n"
"1905\n"
"9251\n"
"\n"
"8153\n"
"12814\n"
"3302\n"
"1661\n"
"11623\n"
"\n"
"3386\n"
"4242\n"
"3179\n"
"7596\n"
"1099\n"
"1223\n"
"6241\n"
"1020\n"
"4869\n"
"4247\n"
"4906\n"
"\n"
"5208\n"
"2362\n"
"5365\n"
"5656\n"
"5553\n"
"2689\n"
"2832\n"
"2248\n"
"2565\n"
"4027\n"
"3744\n"
"4494\n"
"3262\n"
"\n"
"2013\n"
"3397\n"
"2712\n"
"2766\n"
"1050\n"
"6780\n"
"2011\n"
"5529\n"
"6836\n"
"7063\n"
"2265\n"
"\n"
"10758\n"
"6733\n"
"13823\n"
"10328\n"
"11961\n"
"2488\n"
"\n"
"1908\n"
"3576\n"
"2367\n"
"2913\n"
"7258\n"
"6005\n"
"6231\n"
"2573\n"
"2938\n"
"4048\n"
"5005\n"
"5973\n"
"\n"
"4602\n"
"2148\n"
"1414\n"
"1018\n"
"5080\n"
"1286\n"
"7079\n"
"2476\n"
"5975\n"
"3865\n"
"7153\n"
"3292\n"
"\n"
"5474\n"
"2200\n"
"1666\n"
"5834\n"
"6504\n"
"4983\n"
"4229\n"
"5689\n"
"5358\n"
"5298\n"
"4968\n"
"3762\n"
"6038\n"
"6140\n"
"\n"
"8424\n"
"4933\n"
"2202\n"
"8871\n"
"9421\n"
"1163\n"
"10520\n"
"2527\n"
"\n"
"6145\n"
"1123\n"
"3662\n"
"5987\n"
"7112\n"
"8320\n"
"7502\n"
"2351\n"
"\n"
"4890\n"
"2668\n"
"5522\n"
"4488\n"
"1494\n"
"5735\n"
"2009\n"
"5489\n"
"3132\n"
"2789\n"
"1876\n"
"5855\n"
"1277\n"
"\n"
"1597\n"
"3115\n"
"5153\n"
"5194\n"
"5268\n"
"1057\n"
"1302\n"
"4087\n"
"4640\n"
"2687\n"
"1436\n"
"3447\n"
"5824\n"
"\n"
"1836\n"
"7952\n"
"3379\n"
"6602\n"
"10400\n"
"7891\n"
"7102\n"
"6127\n"
"\n"
"6646\n"
"6790\n"
"6513\n"
"4780\n"
"4377\n"
"5911\n"
"2832\n"
"6423\n"
"2909\n"
"4189\n"
"1711\n"
"4975\n"
"\n"
"8072\n"
"5304\n"
"12460\n"
"12406\n"
"7023\n"
"5993\n"
"\n"
"6462\n"
"1631\n"
"6429\n"
"2025\n"
"3339\n"
"7157\n"
"8182\n"
"4927\n"
"3654\n"
"4273\n"
"\n"
"16156\n"
"\n"
"8008\n"
"2078\n"
"2961\n"
"2709\n"
"7088\n"
"2669\n"
"6653\n"
"6788\n"
"\n"
"6810\n"
"3227\n"
"8499\n"
"9527\n"
"3141\n"
"2629\n"
"1326\n"
"2026\n"
"8875";
#pragma endregion;

vector<string> split (string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

int main() {
    int mostCals[3] = {0, 0, 0};
    int mostElfs[3] = {0, 0, 0};

    int currentCal = 0;
    int currentElf = 1;

    for (string line : split(input, "\n")) {
        if (line != "") {
            currentCal += stoi(line);
        }
        else {
            if (currentCal > mostCals[2]) {
                mostCals[2] = currentCal;
                mostElfs[2] = currentElf;
                sort(begin(mostCals), end(mostCals), greater<int>());
                sort(begin(mostElfs), end(mostElfs), greater<int>());
            }
            currentCal = 0;
            currentElf++;
        }
    }

    cout << mostCals[0] + mostCals[1] + mostCals[2] << endl;

    return 0;
}