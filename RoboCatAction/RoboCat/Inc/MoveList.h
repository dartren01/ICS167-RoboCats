class MoveList
{
public:

	typedef deque< Move >::const_iterator			const_iterator;
	typedef deque< Move >::const_reverse_iterator	const_reverse_iterator;
	
	MoveList():
		mLastMoveTimestamp( -1.f )
	{}
	
	const	Move&	AddMove( const InputState& inInputState, float inTimestamp );
			bool	AddMove( const Move& inMove );

			void	RemovedProcessedMoves( float inLastMoveProcessedOnServerTimestamp );
			void	SaveLastProcessedMove( float inLastMoveProcessedOnServerTimestamp );

	//std::vector<std::pair<Move, float>> GetLastProcessedMove()	const { /*return mLastProcessedMoveTime; return mLastProcessedMove;*/ }
	float			GetLastProcessedMove()	 { return mLastProcessedMoveTimestamp; }

	float			GetLastMoveTimestamp()	const	{ return mLastMoveTimestamp; } 

	const Move&		GetLatestMove()			const	{ return mMoves.back(); }

	void			Clear()							{ mMoves.clear(); }
	bool			HasMoves()				const	{ return !mMoves.empty(); }
	int				GetMoveCount()			const	{ return mMoves.size(); }

	//for for each, we have to match stl calling convention
	const_iterator	begin()					const	{ return mMoves.begin(); }
	const_iterator	end()					const	{ return mMoves.end(); }

	const Move&		operator[]( size_t i )	const	{ return mMoves[ i ]; }
private:

	float			mLastMoveTimestamp;
	deque< Move >	mMoves;

	//Move			mLastProcessedMove;
	//std::vector<std::pair<Move, float>> mLastProcessedMoveTime;
	float			mLastProcessedMoveTimestamp;


};