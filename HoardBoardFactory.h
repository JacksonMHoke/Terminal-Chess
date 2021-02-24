class HoardBoardFactory : BoardFactory{
	private:
		pieces[][];
	public:
		HoardBoardFactory();
		virtual Board createBoard();
}
