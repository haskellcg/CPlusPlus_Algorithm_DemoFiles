/**************************************************************************
 * author: haskellcg
 * date: 2020-04-28
 * description: bucket sort algorithm
 *************************************************************************/

#include "bucket_sort.h"

class Bucket
{
public:
    /**
     * @brief destructor
     * @param
     * @return
     * @remarks
     */
    ~Bucket();

    /**
     * @brief default constructor
     * @param
     * @return
     * @remarks
     */
    Bucket();

    /**
     * @brief parameter constructor
     * @param uint32_t nData, data to be sorted
     * @param Bucket *pNext, pointer to next Bucket
     * @return
     * @remarks
     */
    Bucket(uint32_t nData, Bucket *pNext);

    /**
     * @brief get data
     * @param
     * @return uint32_t, the data
     * @remarks
     */
    uint32_t get_data() const;

    /**
     * @brief set data
     * @param uint32_t nData, the data
     * @return void
     * @remarks
     */
    void set_data(uint32_t nData);

    /**
     * @brief get pointer to next
     * @param
     * @return Bucket *, pointer
     * @remarks
     */
    Bucket *get_next() const;

    /**
     * @brief set pointer
     * @param Bucket *pNext, the pointer
     * @return void
     * @remarks
     */
    void set_next(Bucket *pNext);
    
private:
    /*< data need to be sorted */
    uint32_t m_nData;
    /*< pointer to next bucket */
    Bucket *m_pNext;
};

Bucket::~Bucket()
{
    m_nData = MAX_UINT32;
    m_pNext = NULL;
}

Bucket::Bucket()
:   m_nData(MAX_UINT32),
    m_pNext(NULL)
{
}

Bucket::Bucket(uint32_t nData, Bucket *pNext)
:   m_nData(nData),
    m_pNext(pNext)
{
}

uint32_t Bucket::get_data() const
{
    return m_nData;
}

void Bucket::set_data(uint32_t nData)
{
    m_nData = nData;
}

Bucket *Bucket::get_next() const
{
    return m_pNext;
}

void Bucket::set_next(Bucket *pNext)
{
    m_pNext = pNext;
}

void bucket_sort(vector<uint32_t> &vecInt)
{
    // TODO: add code
}

void bucket_sort_test()
{
    print_highlight_msg(">>> Test bucket sort funtion:\n");
    vector<uint32_t> vecSrc;
    get_random_vector(vecSrc, 10);
    print_normal_msg(to_string(vecSrc) + "\n");
    bucket_sort(vecSrc);
    print_normal_msg(to_string(vecSrc) + "\n");
    if (is_sorted_as_ascending(vecSrc)){
        print_correct_msg("CORRECT\n");
    } else {
        print_error_msg("ERROR\n");
    }
}
