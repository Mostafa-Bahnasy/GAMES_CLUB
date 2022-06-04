#pragma once



//--------------------------------------------------

void show_user_data() { // print accounts
	cout << "\n";
	int sizei = arr_acc.size();

	cout <<" |"<< setw(20) << "EMAIL" << setw(20) << "ID" << setw(20) << "TOADD" << setw(20) << "MONEY\n";
	for (int i = 0; i < sizei; i++) {
		cout <<i+1<<": "<< setw(20) << arr_acc[i].email << setw(20) << arr_acc[i].id  << setw(20) << arr_acc[i].toAdd  << setw(20) << arr_acc[i].money << "\n";
	}
}
//--------------------------------------------------

void show_help() {
	// print all commands
	cout << "\n<help>\\command.print--\n\n";
	cout << "1.system\\git.show_accounts\n{}\n";
	cout << "2.system\\delete.account\n{\n  < insert ID > \n}\n";
	cout << "3.system\\cmd.help\n{}\n";
	cout << "4.system\\admins\\add\n{\n<Dragons>\\new.admin\\email.\n}\n";
	cout << "5.system\\client\\approve\n{}\n";
	cout << "6.system\\client\\reject\n{}\n";
	cout << "7.system\\options\n{\nsounds\\volume\nsounds\\songs\ncredit\nexit\n}\n";
	cout << "8.system\\client\\add\n{\n<Dragons>\\new.client\\email.\n<Dragons>\\new.client\\password.  \n}\n";
	cout << "9.system\\cmd.clear\n{}\n";
	cout << "10.system\\admins.comment\n{\n}\n";
}
//--------------------------------------------------

void delete_acc() {
	cout << "<insert ID>";
	string id; cin >> id;
	int i;
	int sizei = arr_acc.size();
	for ( i = 0; i <sizei ; i++) {
		if (arr_acc[i].id == id) {
			// hand maded erase element
			for (int j = i + 1; j < sizei; j++) {
				arr_acc[j - 1] = arr_acc[j];
			}
			sizei--;
			break;

		}
	}
	cout << "PROCCESSING\\\n"; Sleep(500);
	if (i >= sizei) {
		cout << "THERE IS NO SUCH ID\n\n";
	}
	else {
		cout << "DELETED SUCCESFULLY\n\n";
	}
}
//--------------------------------------------------
void add_admin() {
	accounti newAdmin;
	newAdmin.id = "admin";
	newAdmin.money = 1e9;
	newAdmin.password = "admin123";
	cout << "<Dragons>\\new.admin\\email."; cin >> newAdmin.email;
	bool is = 1;
	int sizei = arr_acc.size();
	for (int i = 0; i < sizei; i++) {
		if (newAdmin.email == arr_acc[i].email) {
			is = 0; break;
		}
	}
	if (is)
		arr_acc.push_back(newAdmin);
	else
		cout << "FAILD!\n";
}

//--------------------------------------------------
void add_client() {
	accounti newClient;
	newClient.id = make_unique_id();
	newClient.money = 1e3+1;
	cout << "<Dragons>\\new.client\\email."; cin >> newClient.email;
	cout << "<Dragons>\\new.client\\password."; cin >> newClient.password;
	int sizei=arr_acc.size();
	bool is = 1;
	if (newClient.password.size() < 8 || newClient.password.size() > 20)is = 0;
	for (int i = 0; i < sizei; i++) {
		if (newClient.email == arr_acc[i].email) {
			is = 0; break;
		}
	}
	if (is) {
		arr_acc.push_back(newClient);
		cout << "SUCCESSFUL!\n";
	}
	else
		cout << "FAILD!\n";
}
//----------------------------------------------------
int id_exist(string s) {
	int sizei = arr_acc.size();

	for (int i = 0; i < sizei; i++) {
		if (s == arr_acc[i].id)return i;
	}
	return -1;
}


//-------------------------------------------------
void rejection() {
	string s;
	cout << "<reject>\\id.get\\"; cin >> s;
	int index = id_exist(s);
	if (index > -1) {
		arr_acc[index].toAdd.clear();
		arr_acc[index].added = false;
		cout << "SUCCESSFUL OPERATION!";

	}
	else {
		cout << "Faild!\n";
	}

}

//--------------------------------------------------
void approvement() {
	string s;
	cout << "<approve>\\id.get\\"; cin >> s;
	int index = id_exist(s);
	if (index>-1) {
		arr_acc[index].money += stoi(arr_acc[index].toAdd);
		arr_acc[index].money = min(1LL * 1000000, arr_acc[index].money);
		arr_acc[index].toAdd.clear();
		arr_acc[index].added = false;
		cout << "SUCCESSFUL OPERATION!";

	}
	else {
		cout << "Faild!\n";
	}
	
}

//--------------------------------------------------
void show_comments() {
	for (int i = 0; i < adminChat.size(); i++) {
		cout << adminChat[i].nm << ": " << adminChat[i].mess << "\n";
	}
}

//--------------------------------------------------

bool operations(string& s) {
	if (s == "system\\git.show_accounts") {
		show_user_data();
	}
	else if (s == "system\\delete.account") {
		delete_acc();
	}
	else if (s=="system\\cmd.help") {
		show_help();
	}
	else if (s=="system\\admins\\add") {
		add_admin();
	}
	else if (s == "system\\client\\approve") {
		approvement();
	}
	else if (s == "system\\client\\reject") {
		rejection();
	}
	else if (s == "system\\options") {
		string opt;
		cout << "<option.No>"; cin >> opt;
		if (opt == "sounds\\volume") {
			int newVol = back_sound.getVolume();
			cin >> newVol;
			if (newVol < 0)newVol = 0;
			if (newVol > 100)newVol = 100;
			back_sound.setVolume(newVol);
		}
		else if (opt == "sounds\\songs") {
			int songNo = 0; cin >> songNo;
			if (songNo > 3)songNo = 3;
			if (songNo < 1)songNo = 1;
            //-----------------------
			if (songNo == 1) {
				back_sound.stop();
				back_sound.setBuffer(song1);
				back_sound.play();
				back_sound.setLoop(1);

			}
			else if (songNo == 2) {
				back_sound.stop();
				back_sound.setBuffer(song2);
				back_sound.play();
				back_sound.setLoop(1);

			}
			else {
				back_sound.stop();
				back_sound.setBuffer(song3);
				back_sound.play();
				back_sound.setLoop(1);

			}
		}
		else if (opt == "exit") {
			return 0;
		}
		else if (opt == "credit") {
			cout<<"\nMembers:\n";
			cout << "1.Hisham waleed\n";
			cout << "2.Marcus Max\n";
			cout << "3.Ali Ibrahem\n";
			cout << "4.Ahmed swilim\n";
			cout << "5.Omar saeed\n";
			cout << "6.Mohamed Elofy\n";
			cout << "7.Mustafa Bahnasy\n";
		}
	}
	else if (s=="system\\client\\add") {
		add_client();

	}
	else if (s == "system\\cmd.clear") {
		system("cls");
		cout << "Dragons  [Version X]\n";
		cout << "All rights reserved";

	}
	else if (s=="system\\admins.comment") {
		show_comments();
	}
	else {
		cout << "FAILD!\n";
	}
	Sleep(1000);
	return 1;
	
}


//--------------------------------------------------

bool to_run_cmd(accounti admin) {
// console
	system("cls");
	cout << "Dragons  [Version X]\n";
	cout << "All rights reserved";

	while ("true") {

		
		cout << "\n\n";
		cout << "Dra:\Admins\\bahnasy>";
		string op;
		cin >> op;
		if (!operations(op)) { break; }

		//system("cls");

	}
	cout << "system\\close.delay(1000ms)"; Sleep(1000); cout << ".terminates\n";
	return 0;
}