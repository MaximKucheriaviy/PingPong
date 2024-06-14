
TextBox whinerName("Test", &arial, 42, 1, 1, 400, 200);

void resetTimout() {
	resultsScreen.disable();
	mainMenu.enable();
}



void resultScreenSetup() {
	resultsScreen.addObject(&whinerName);
	app.addScreen(&resultsScreen);
}

void setupResultScreen(string winer) {
	Timeout resetTimoutRun(resetTimout, 3000);
	resultsScreen.setTimout(resetTimoutRun);
	whinerName.setText(winer + " win");
}