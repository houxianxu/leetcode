// http://oj.leetcode.com/problems/reverse-words-in-a-string/
 
 #include <string>
 #include <stdlib.h>
 #include <string.h>
 #include <stdio.h>

 using std::string;
 using namespace std;
 
 void c_solution(char *str) {
 	if (*str == '\0'){
 		// printf("%s\n", "D");
 	} else {
	  	char *pch;
		char res[100000];
		char *wordP[100000];
		int i = 0;
		int j = 0;
		pch = strtok(str, " ");

		while(pch != NULL) {
			wordP[i++] = pch;
			pch = strtok(NULL, " ");
		}

		/* copy word from wordP inversly to res */
		strcpy(res, "");
		i--;
		while(i >= 0) {
			// printf("%s\n", wordP[i]);
			strcat(res, wordP[i--]);
			// printf("%s\n", "d");
			if (i >= 0) {
				strcat(res, " ");
			}
		}
		strcpy (str,res);
	}
 }
 
 class Solution {
 public:
     void reverseWords(string &s) {
       char* c_s = new char[s.length() +1];
       memcpy(c_s, s.c_str(), (s.length() + 1) * sizeof(char));
       c_solution(c_s);
       s = c_s;
     }
 };	

 int main(int argc, char const *argv[])
 {

 	char s[] = "my name is houxianxu";
 	char s1[] = "hwf akgsvxoum.srls!q?kzn,eobptjwuzprb?pcvgzf wbf,aaouridwjwtsc'niveqfkpozoobgi fjhwnb,blgljndzajmidf'm?kjgyq? gbfmh'ue.j!wxglvbrloqrafdpw.il. '.bn,q t!gwpcze.oldse?mgyd mtevhswavug?,ewj.put !aufzbh.ae,sb!beislnxnckf,gwywyzt,abctetwh.lmf o''qbtme gmddllify.wl 'syydjfbhjvn'ojjmqenzc,qltwsh?c'hhaekq 'ez?wwwcfqodu?pihxgk'?.szri!uzojwzuwlq om.!'syg'adeipju!b,xcsey!xc'a bfam.aneqfvhhgmjdzt 'g'qjhrbv'nvhqam !dq.shky zuobo.izdiyohgo?ujbfxflt jvmlvvgkrdctjgzqvv .cfgytbcyvnqbmww?gxngeosapb.!!kuamboyqqwmqk!a? rknzvobq,dgwaoto t.zad !qfxe?.ryy?wv,ak?m',.o?qqkrj,!ozyjrd.vtextgj!ou, xd'km?ygjglw !p qnidte .uekbnr dkkrc,!zamblixkct!cb.pr?? rrmv.set'omcxlpazpnxjwlz.nverodxdp?xja'!.tsp lc?ymts?.yzx..vgsfpkg,t?pzllbcrnx'fcncvuxrd ypwf,l.skdde?uln,wlrhbnmqpo,jsrpe wy.hfzhdxtvndnvvq,ikkdk,ipeam.'f?lnlja.rumfz ?rxp'zadiir!qste?'dzhi e?inciz!j'cujhwjsksprtfp!jgnjkpgpc' k!?kcifo,v,a'ut s,mlg!wjrjv kmobuu,m.esraqrmtw sznknlmq?t!an,fvwvriufwloia!wlq?hwuekkl mvm!!zeuwvkhzapsacp!n?!e.x.p!m!'rutdgvjcs.fc fqmxvy?rab.g?.cmpnfbwien!kblavkhvosai,,lmpghzoe'sp itxctib,mpjlcahsmxylueyntdm,ywmc xp,uqowujn? vsuzfjw?rdojv vc!vkofe.c,nx.kffyk!sua'nsgdjp. ! fbdle,c''?h.kyxw,vuuzhzotempwxkybjm,yglgcvysckaxb stxnb fyrcu,aabfxxmaz!.,stk.p?vfykzfuwpvw? pe!oyzcxb?lvsalfaed,!,qm!npggna wmv!ueuy!b?evldesa luazhx!iith,s.emffnyhklyc'rwoq,!gu.l?! e.?evzi.ufrvrvzchqvz.rs,',.gny!r sobjyorx.bdo.zhhbkjkxmo'thxue'kwbezrkdv. tplkx!z,oryq lqx,yxq cqvekwwudwxnklhdjz,evibz.sea? ?nfpf'wgiv.kyx 'vd'gcwwq,y!!lujmbejhwl,!labqrozz!cl.,wkipz,t fg!isc!!lcm ,!?.n?viuzy.hforu.sst,xwdrztcbbe nwnh.t!bej,sy egx.cv?epas ctoqczgt!qofbcbznuljj?u flur!d.eyszafbvwmzynq!hdjpk zta!swbqviuypt'znizoibbszif.exgsnafvk ygo fue.srbbnxzobiuthw kpf?yjqyaljcvkls,xb.pj!k!ulu.iajfq?t,g,f,?fr?g !djmxrk usia?ea,pnu.,z',mbh? n!nm!dasf dpevecnqj' o'qgj!rwmlaga.dwdtncndqocz kgtovolylwzowf.jahhn 'kmft ihtubjrzv??, h oy.jzu!rkmmhuhn?sciawfaucrwcy,alzgnl'?wxzu'evn? rcgkknlhji u!qh??fx'icaudaxtnircm m axeyxgq',yfnuhmojwe'hp'm sb,ho,r ??d bcpud kiufkaom,,.utfifnzdgldyzcnbsneny!!wvv?d rmrae,nq,zxfm!!baqigpsgvbxcqie.z!sfoel?ln?fvwq amfomuzx ?jko hxr.chuacwnxrofnaqxk?b?d?fdq.mbp gqlw fmjg en.bhsatgwylabue!!.lezqjvxnx?anw'wpp?rgcw.ywcrs puvk,?bst'imlbkswr'p.q?olw?f.kpwqu'x'cq 'jjzc'?tgctbtrndyavasyeuzewkrgenz?wv.fc vmdlk icm?'f'rcnbil'!o?wtzlgbdea,s.a!kfe!rvyt? wqsb?mmuqmqwniig??iqzqjdykegem?yt!zye?v gcuizkaqlgkmo tnvkmmecjtgdhpvivodvvupgkbdejdl!ro! ei!gfvllofmy,jllywr.?g.rk ,!momgyulpomhgeo.vrh?wazlqg?ze? ,fwjd.,uzrytnsny xhsteasnaxigc..ru,,ejhbkyov,,j lo ux?su?xwb,grzvtqvyb'kxs!g.rwrcsfktdsc kef?ndjkre!vl'msdzs',iaqrrrvu,itakaw xlhxkbvosbt.k!mbuv!yllojc,cq hs'r!zqxu',dp vjwwbiirbzvemqg..irosy!obpn mdknxyms?bnv,iallpxkbbo eumykmh,.ntfbirmycyihd?q,ltbhujpwo!!hk ywr !valbtnrtdqt'srqclbxz'cze!hdppjrtqb'fap,,nkyst.ju sjkntc,ic!'tagajlkfjvnexqbr,dibjsw!w ow!uermg.djfqxxdiu,m.q? g,iw?pfalmt'kcdbtdvtvissczfy,d?!vdhc?bl cf?kwqycuk?,'f lp!lofn ydx'bns.nwep?'?qph kngzl?n'hk!x.kvkjkesckcmrc.jesalc?no'mk q cbbdbm,!dbnofxvo, jeuc, r?!d!f'ijpydwogpwsihh.blh!go ymmgnv, ?e.v?i?xz?v,tk?wrol! mdxoztriimacbeurmhhsmh',spi.e'wto?thiay fmodmqdyfbf.nemrf?kv?amj' ,dmewowmyotluccgexoxw,tgr.hodyc?eih!ok ngiay!p?invbucunj!bgnoe.,ovudz p'ktkpxsihb!pwxaswmq!r rkyipwoa ,fu voabrtusg.yumeirf??'qjcyc,yvdsehu qai?lukvdhtsbafknitcbj,own? cotrmr,jyjmp.xolmrktldxwyp?f?jvqndcfap'ivshzyppn, vzp?fzpvmmgxj pbhel!hqdplybc'j.yuk ? vmri'mlxjrhtoprgbfytujhyh fohy,'jj!bcidhhqr edetuthm'uv?gm?egnw'hkvdv eif ocpxciekygx.puk!hlvc'kykvczgqvn .''rmq'eifs!qogfpius!mx vhcmna.ffm'xvl!qjjdjpdcvgu!gl lg?bc.d?rmv!pvltzol k.adnbum..qlyayuccnpmqkkfaajx.q.bmnta'fw iwcjj!phoogu,.z ypwyil!cc!ost'au,fjc!'xs.jsbghjoktaw.hv,s ig.p nku!,ll?ay vjg!wcdmw'.pwqaqyyahrufv zhxcdkrpvltsxycqj,!gqwry wf'lilxeq,?y,mknrp'!vh'zidd?chdat,vxvz.ug wrxbiql'ipmmzlb.!z'eyapfru!tw.j. rxmni!bdbrcv,?azykjcavcioft'ewzf'nmia !lyjhgoqmcbxuibo?s?hg,vkjlo.evnrw krxbryzee,kszxschftiznhuvf'xmyxxm!uywu' vlveerzhqym!s?kmbq?utoceo.apjghx' wj?rfqiaygik'pa o??wntnzxrw cryxhvtz!pcl?oaq,!mlkt?!y ur'h,?p.vhq zm,t?f'qdwbxshyojalbcbt,xqv'?sk' ,nanp!kqmoqft,i.!nejrg,'h.ai.drqqpxh mjyczuuwohci'ugbzkdiggydhzwjc 'm ?bd,nsbiw.obkkjbfclf m.gbjhe.oxdvowpcptohls!kc''!h wi.voqqkooipd bs!zmqt.nkvf,plfcw.a.m !ylhagb'.gnpcd?hfc!kvscv!hnkaipo.astugbrjq,svu. qv?y'wq.htw qz vmfk.umdtgggc.lbv'db shsgqr'nb hujaf eyrr!zfzqtva!? c?ldmkatcfrjxa veqx,rq.?zanbiascjdzqidb.qtale?!dcwvpwcig wttbc',zsncspwuzfl'!jte?c?k,. ?,xvjdfdivzrcw.jaiuknvylfhppdilefynm'.z.nirkwbdttg mdoicjibmj,obpvveccnm wehc?!xfkbw.lg,.icsnqeboclhb!d iurvuw,irthrdzfzq,.qulogovpgb nlnqlfcbm?rwou. v,,rq?mrofdtw't .kbsogljzkojv b?n?,z c,kscao?anqmwjy,ztipwpbtoi.no xdvidgbhxcc r!ooxpcqhr'inlqu.nndslowxf!.isk i,vxmqizcejnab ,!'!wvkdlldxrdwdww,. ysfgi'.z!jgngrxmlflt?,cauxfck ?fgrchfgcyfz ay'!descf?mjf'epnf,t wrqfuqj?xiyfn .psebscarsavtp!habiu. bxe ufxphnltplfmij qwk'wqvj, ucplktaxv'y uvf'zxk?k?okmdn,jm,rho rnlmmafbw?c yaune,szqg.znpej'vvwy,tbkb,ds?rvo,b gjfn'pd.y?bowb.d,vgb?.og.hp?bpn pzedb,dfmaxiupzt?wl vok?dwsmsgq na'nssoieccs'yxki agrwm pkoidpya'pggck !v!'a?ji.ibqcogxem'yqxts?tum mwgosp!qrct.iqxsdbd.cuzaxqcwr fahawzekls !vedw!.wkdvp ? bvevfzmdcpbwynktassxajxkr mz'a!qezfdfxljkdunmfeq.oudh!?oa'pav lhaxmxn.v ?oarurl?.wyn t?rg!wla'gtvry,!ipziz!,u? ?umh.xbn?qxgjgfid..qhuwwgbt'qb .v'dkxpxr!ck!atoa?'h,kc loaklf!pewhyshmwo.aopa.? mknaudgpfvz?!upd'oyn'bvp.f,sod eijkaeupzamtlm!czpa!'leedyd.u hxtpkzgq!yjjuk?be''vykvxnfdtsfhq,aptvla,grgr rivaytgax yaygwfnmzr.a'z'hsj !vgt' x,bispawerjebpc'keqy?rhjhdvl ix.ggue,axpoydl.rjdnjz 'f'bqodjcsrnnuroldp bsqyp?xmxtjgm.wvrmtltyvelydxivltydfytifid jj'pxwwzbwbosfq!l!ghpo'wmasfo!ulbogooskm?.pfc!n k.ixo mtk,sh !rfrstl'hstzdwa,qfq!ycq.z.eimvsknnct.ebskpnugk. psou,pyywu'vkwravwzmv.zlisddz.tcwfin?hwvfhxvxs 'k!o,in'w ylvkjcbqwf.gqokjl?bmbs,pobqzv. dhppvi?mowlqrr.cmptqgb?azprnp,t 'cplhnemikccmqgxoo.zczstqs,ig.hzasnjnbd bef!'g,jbyukxlpihyddi!?mq. .pnojrghzuhodsy?hps,vf,owwpu,.llr'.rb.eb'bf k !py!!ou'mmszvk,gnavb,tqmj,f.fxv,,'xljrumcy,lfdc?s b?,.iytyabvh'!e'vxotow'!qnq knw?!qpftfxtpk?n?ryrt!zqu.szxumjynnepag,ocuvhmai w?yancxklweyurtudbxwifms.crwfsjxwnr zgbnkkykb.pncoo'layftjnwfi,rigby dm.ssjdr'nyevn vvqkcbvoth.ipjffn lkq?st'vvzmwul?ea!yf!igmfukacxosuuctepsmwxfk!edax mfroco.nfy nbcu cpnlg nuqap!u?lhxallmae?gchmsydqituqy.ikivwf seih?h umdaaeybykx,ykqyh'jyjnxfqhhanfksozebddeiaobiit ss gghblmvdzjenq,k,lpcsu?heypfcec qgxfd,ubqcuxtvczo?c'szorotldbgyyb..dwlmqmeiom x,el!sanzb'hbwhmazr!ne,mepy?nt!f? fkorne!jdoelyf! tqpoeutn!ezygazqvercngztaozl?okotaf..yiv bru,d,e.y?o nyygwrp'jaqv.ob'!n.lfiskhwsqixu?m?,iaj o'g'eiwlmenl,eyyafb'p'mdgcdwtesvpibs,pvasz,lxow tkcwcxrt ekt!aglbd'waiz'byhicopvom!kljrzz?mj,' k,xf'pn mgwkxcpnrxatdhau?cmbqznnzlaaj!d.ehzfj,k!ec ibt evtx?vqi!kkas?,vgxrsyvdsqd!b,wghpbkcaig adnimobw,'vydr.pjgzncwrl!nk!wadrbya!brycwtnc ga?fpsze,xg'vfapoba,'rembu !'xp'!,v.u!vvzdf'krvoqv!m? v!zp,t,wcwchnffztaxcpfvbqpyef'!ky!, yjfwrf..y'czxzb?swwv.xl. v,??jzpcn!m?aun!njvk.!rmn!pwndznxehlf,aoct rftb!.al?r.uejqv,vzbo' ,tq!g?.ddsib,hby?jmq,,l!kkqt,x?ntomgyqbyuh llflquoiaydbcvrfa z!uf!uqams.lktiw?d?qzxvwummz,t.ba?grzxtq,zw xiu!ogkwxurcjui.hm tw.imgocuwmanmpgeua.ijhcqfhykv tu'jb?!iqezihd.elqoijooonavf,sqcst???!sqkhih?gtqil lvoodvvvhxndjdsbomfosdezbrifuo' rye,wxqclngggrcbeg kqczsl.g,cudxd?pifr'gyziukjtc'noqcvdw',k dcwdis!iaxmq kp'l,ticsizd.m?xld'jtyundc'a?yd !s zmlwci h.ehbxww?hhbc'dtphxznw,,dlpfg. .ugfyjc!iw?nydwl?pbr'oemt,vuo'gswv,pnuzfpyhelxfbkd";
 	c_solution(s);
 	// printf("%s\n", "d");
 	printf("%s\n", s);
 	return 0;
 }