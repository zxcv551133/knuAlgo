import java.util.*;
public class boggleGame {
	static char[][] map = new char[5][5];
	static final int[] dx = {-1,-1, -1, 1, 1, 1, 0, 0};
	static final int[] dy = {-1, 0, 1, -1, 0, 1, -1, 1};
	static boolean hasWord(int x, int y,  String word){
		//1. 시작 위치가 범위 밖이라면 그냥 바로 실패.
		if(!(y>=0 && y<5 && x>=0 && x<5)){
			return false;
		}
		//2. 첫글자가 일치 하지 않으면 실패.
		if(map[y][x] != word.charAt(0)){
			return false;
		}
		if(word.length()==1){
			return true;
		}
		//인접한 8개의 칸을 검사한다.
		for(int direction =0; direction< 8; direction++){
			int nextY = y+dy[direction];
			int nextX = x+dy[direction];
			if(hasWord(nextY, nextX, word.substring(1))){
				return true;
			}
		}
		return false;
	}
	public static void main(String[] args){
		Scanner input = new Scanner(System.in);
		int tc = input.nextInt();
		for(int j=0; j<tc; j++){
			for(int i=0; i<5; i++){
				String mapping = input.next();
				for(int y=0; y<5; y++){
					map[i][y] = mapping.charAt(y);
				}
			}
				int check = input.nextInt();
				for(int a=0; a<check; a++){
					String boogle = input.next();
					boolean first = true;
					int cx=0, cy=0;
					for(int tx=0; tx<5; tx++){
						for(int ty=0; ty<5; ty++){
							if(map[tx][ty] == boogle.charAt(0)){
								first = false;
								cx = tx; cy=ty;
								break;
							}
						}
						if(first == false){
							break;
						}
					}	
					if(hasWord(cx,cy,boogle)==true){
						System.out.print(boogle);
						System.out.println(" YES");
					}
					else{
						System.out.print(boogle);
						System.out.println(" NO");
					}
				}
		}//tc다돌리는것 

	}

}
