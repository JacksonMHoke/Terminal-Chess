class BoardFactory : Game{
	private:
		pieces[][];
	public:
		BoardFactory();
		virtual Board createBoard()=0;
}
