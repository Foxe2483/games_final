#include<iostream>

using namespace std;

int main() {
	
	int  mapX, mapY;
	char inp;
	int score = 0;
	int energe = 0;

	cout << "WASD,E,123,Q" << endl << "Map X size:";
	cin >> mapX;
	cout << "Map Y size:";
	cin >> mapY;

	int cx = mapX / 2, cy = mapY / 2;

	char map[mapX][mapY];
	
	for(int y = 0; y != mapY; y++){

		for(int x = 0; x != mapX; x++){

			map[x][y] = '.';

		}

	}

	map[cx][cy] = '+';

	while(2483){

		cout << "\n\n\n\n\n";

		score = 0;
		energe = 0;

		for(int y = 0; y != mapY; y++){
	
			for(int x = 0; x != mapX; x++){
			
				if(x == cx and y == cy){
					cout << ">";

				} else {
					cout << " ";

				}

				if(((map[x - 1][y] != '+')  
and                 (map[x + 1][y] != '+')
and                 (map[x][y - 1] != '+')  
and                 (map[x][y + 1] != '+')) and (map[x][y] != '+') ){
					map[x][y] = '.';

		    	}

				if(map[x][y] == '+') {
					score = score + 1;

				} else if(map[x][y] == '}') {
					score = score + 2;
					energe = energe + 3;

				} else if(map[x][y] == '(') {
					score = score + 3;
					energe = energe - 1;

				}
	
				cout << map[x][y];
	
			}
	
			cout << endl;
	
		}

		cout << "Score:" << score * 10 << endl << "Energy:" << energe;
		if(energe < 1){cout << "!";}
		cout << endl;

		cin >> inp;
		if(inp == 'q'){
			break;
		} else if(inp == 'w'){
			cy--;
		} else if(inp == 'a'){
			cx--;
		} else if(inp == 's'){
			cy++;
		} else if(inp == 'd'){
			cx++;
		} else if(inp == 'e'){
			map[cx][cy] = '.';		

		} else if(inp == '+' or inp == '1'){
			map[cx][cy] = '+';

		} else if(inp == '}' or inp == '2'){
			map[cx][cy] = '}';

		} else if((inp == '(' or inp == '3') and energe > 0){
			map[cx][cy] = '(';

		}

	}
	return 0;//dedas
}
