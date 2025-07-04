class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int n=ceil(log2(k)), shift=0;
        for(int i=n-1; i>=0; i--){
            if(k > (1LL<<i)){
                shift += operations[i];
                k -= (1LL << i);
            }
        }
        return 'a' + (shift)%26;
    }
};

        //yooo netal
   // abhi bhaii y bhi hota kya???
   // haaaaaaa!!!!
   //wowww 
   //mei book padhri thi abhii y question dikh gaya ,... gfg ke 2 purane pod kiye - noiceeeeeee--> panchat the pr --> haaa sliding window ke classics-->>> uska 3rd day kA BHI SAME H BASS STRING H (HASNE WALA EMOJI)
   //BSDK QUESTION KAR MKO TOH Y HARD DEKH KAR PADHNE KA MAN NAHI KARA
   // bhok me jaa
   // solve karra mai ab
   // btw simple hai, soln aa gya hai dimaag me, ab bas implementation karna hai proper--> TU Y NAHI BHI BOLTA TOH MEI QUESTION PADHTI PAR GOOD ABE YAAR LIGHT GAYIIII BHAII VAPASSSSGOOD
   // fuck off--> OHKAYY ()\U0001f602--> ABE EMOJIII ABE ABEEEE QUESTION KAR N BHAIII KT=YA TIMEPASS KARAA AUR MKO CODE BHJ VOH NODE WALAAA IGNORE KIYA MERA MSGGGGG KHARAB LICHAD ADMI

   // \U0001f602\U0001f602\U0001f602\U0001f602\U0001f602\U0001f602\U0001f602\U0001f602\U0001f602\U0001f602\U0001f602\U0001f602\U0001f602\U0001f602\U0001f602\U0001f602\U0001f602\U0001f602\U0001f602\U0001f602\U0001f602\U0001f602\U0001f602\U0001f602\U0001f602\U0001f602
    // konsi?
    //bhaiya ki h tiny remarkable results : atomic habits
    
    
    // ruk yahi bhejra --> NAHI BHAII PLEASE  NAHII N PAGAL H KYAAAAA SOLUTIPN LIKH ISKAA MEI BHI PRASHN PADHTI 
    // bhej diya, yaha se le lena alag se nhi bhejunga---> ha ha thik h
    
    
    
    
/*    
    
//Middlewares
app.use(express.json()); // Middleware to parse JSON bodies
app.use(express.static('src/client')); // Middleware to serve static files from the client directory

// app.get('/', (req, res) => {
//   res.sendFile('index.html', { root: __dirname + "/../client/"});
// });

// app.get('/client.js', (req, res) => {
//   res.sendFile('client.js', { root: __dirname + "/../client/"});
// });

// app.get('/styles.css', (req, res) => {
//   res.sendFile('styles.css', { root: __dirname + "/../client/"});
// });
    
*/   //isko aaisa hi rehne de
// mai ohkalyiykyhra code
// mei timmer lagati 1 ghante ka chal andhere mei padhti (ambetkar lamp mei padhte the mei laptop ki light mei padhungii ) \U0001f602\U0001f602\U0001f602\U0001f602\U0001f602\U0001f602\U0001f602 tune copy paste kiyaaa y bhi wtff yaha tab nahi h hariii \U0001f602\U0001f602\U0001f602\U0001f602\U0001f602


// ayooooooooooooo done ✅
