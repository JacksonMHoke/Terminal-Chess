class ClassicBoardFactory extends BoardFactory{
	private:
		pieces[][];
	public:
		ClassicBoardFactory();
		virtual Board createBoard();
}
