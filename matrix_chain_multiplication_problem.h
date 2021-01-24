/**************************************************************************
 * author: haskellcg
 * date: 2021-01-14
 * description: matrix chain multiplication problem solution
 *************************************************************************/

#ifndef __MATRIX_CHAIN_MULTIPLICATION_PROBLEM_H__
#define __MATRIX_CHAIN_MULTIPLICATION_PROBLEM_H__

#include "common_types.h"

/**
 * @brief topics about matrix chain multiplication
 *          words:
 *                  vertex      => vertices
 *                  matrix      => matrices
 *                  hexagon     => https://en.wikipedia.org/wiki/Hexagon
 *
 *          matrix chain multiplication wiki:                 https://en.wikipedia.org/wiki/Matrix_chain_multiplication
 *          matrix chain multiplication youtube introduction: https://www.youtube.com/watch?v=prx1psByp7U
 *
 *          catalan number:       https://mathworld.wolfram.com/CatalanNumber.html
 *          catalan number:       https://en.wikipedia.org/wiki/Catalan_number
 *
 *          Chin-Hu-Shing Approximating Algorithm:
 *                                https://pdfs.semanticscholar.org/e8b8/40a921f7967b30ac161b3dd9654b27998ddb.pdf
 *
 *
 *          Hu & Shing:           http://www.cs.ust.hk/mjg_lib/bibs/DPSu/DPSu.Files/0211028.pdf
 *                                http://www.cs.ust.hk/mjg_lib/bibs/DPSu/DPSu.Files/0213017.pdf
 *
 *                                [PART I]
 *
 *                                The diagonals are the partial products. A partition of an n-gon corresponds to an alphabetic 
 *                            tree of n-1 leaves or the parenthesis problem of n- 1 symbols (see, for example, Gardner [6]). It 
 *                            is easy to see the one-to-one correspondence between the multiplication of n- 1 matrices to either
 *                            the alphabetic binary tree or the parenthesis problem of n- 1 symbols. Here, we establish the 
 *                            correspondence between the matrix-chain product and the partition of a convex polygon directly.
 *
 *                                LEMMA 1. Any order of multiplying n- 1 matrices corresponds to a partition of an n-gon.
 *
 *                                LEMMA 2. The minimum numbers of operations needed to evaluate the following matrix chain products are identical.
 *
 *                                The diagonals inside the polygon are called arcs.
 *                                In a partition of an n-gon, the degree of a vertex is the number of arcs incident on the vertex plus two.
 *
 *                                LEMMA 3. In any partition of an n-gon, n not less than 4, there are at least two triangles, each having a vertex
 *                                         of degree two.
 *
 *                                LEMMA 4. Let P and P’ both be n-gons where the corresponding weights of the vertices satisfy wi not less than wI. Then the 
 *                                         cost of an optimum partition of P is less than or equal to the cost of an optimum partition of P’.
 *
 *                                In the rest of the paper, we shall use V, V2," ", V, to denote vertices which are ordered according to their weights
 *                                After the vertices are labeled, we define an arc V-V. to be less than another arc V- Vq
 *
 *                                We define a partition P to be lexicographically less than a partition Q if the ordered sequence of arcs associated with
 *                                P is lexicographically less than that associated with Q.
 *
 *                                When there is more than one optimum partition, we use the l-optimum partition (i.e., lexicographically-optimum partition)
 *                                to mean the lexicographically smallest optimum partition
 *
 *                                THEOREM 1. For every way of choosing V1, V2, (as prescribed), there is always an optimum partition containing V1- V2 and VI- V3.
 *
 *                                COROLLARY 1. For every way of choosing Vx, V,... (as prescribed), the l-optimum partition always contains Va- Vz and V- V3.
 *
 *                                A polygon having .Va adjacent to Vz and V3 by sides will be called a basic polygon.
 *
 *                                THEOREM 2. A necessary but not sufficient condition for Vz-V3 to exist in an optimum partition of a basic polygon **FORMULA**
 *                                           Furthermore, if V2- V3 is not present in the l-optimum partition, then V1, V4 are always connected in the l-optimum
 *                                           partition.
 *
 *                                LEMMA 5. In an optimum partition of an n-gon, let Vx, Vy, Vz and Vw be four vertices of an inscribed quadrilateral V and Vz are
 *                                         not adjacent in the quadrilateral). A necessary condition for Vx-V to exist is **FORMULA**
 *
 *                                A partition is called stable if every quadrilateral in the partition satisfies Lemma5 FOPMULA
 *
 *                                COROLLARY 2. An optimum partition is stable but a stable partition may not be optimum.
 *
 *                                We define Vx - Vz to be a vertical arc if
 *                                          min (Wx, Wz) < min (Wy, Ww);
 *                                          min (Wx, Wz) = min (Wy, Ww), max (Wx, Wz) <= max (Wy, Ww);
 *                                We define Vx- Vz to be a horizontal arc if
 *                                          min (Wx, Wz) > min (Wy, Ww), max (Wx, Wz) < max (Wy, Ww).
 *
 *                                COROLLARY 3. All arcs in an optimum partition must be either vertical arcs or horizontal arcs.
 *
 *                                THEOREM 3. Let V and Vz be two arbitrary vertices which are not ad]acent in a polygon, and Vw
 *                                           be the smallest vertex ]rom Vx to Vz in the clockwise manner Vw Vx, Vw Vz), and V be
 *                                           the smallest vertex from Vz to V in the clockwise manner, Vy Vx, Vy Vz). This is shown
 *                                           in Fig. 6, where without loss of generality we assume that Vx < Vz and Vy < Vw. A necessary
 *                                           condition ]’or Vx- Vz to exist as an h-arc in the l-optimum partition is that
 *                                           Wy < Wx <=’Wz < Ww.
 *
 *                                COROLLARY 4. A weaker necessary condition for Vx- Vz to exist as an h-arc in the l-optimum partition is that
 *                                             Vx < Vy < Vz < Vw.
 *
 *                                We call any arc which satisfies this weaker necessary condition a potential h-arc.
 *
 *                                COROLLARY 5. Let Vw be the largest vertex in the polygon and Vx and Vz be its two neighboring vertices. If
 *                                             there exists a vertex Vy such that Vy < Vx and Vy < Vz, then Vx- Vz is a potential h-arc.
 *
 *                                Two arcs are called compatible if both arcs can exist simultaneously in a partition.
 *
 *                                THtSORtSM 4. All potential h-arcs are compatible.
 *
 *                                The process of cutting out the largest vertex can be made into an algorithm which is O(n). We shall call this
 *                                algorithm the one-sweep algorithm. The output of the one-sweep algorithm is a set $ of n-3 arcs.
 *
 *                                The one-sweep algorithm, Starting from the smallest vertex, say V1, we travel in the clockwise direction around
 *                                the polygon and push the weights of the vertices successively onto the stack as follows (Wl will be at the
 *                                bottom of the stack).
 *                                (a) Let Vt be the top element on the stack, Vt-1 be the element immediately below Vt, and Vc be the element to
 *                                    be pushed onto the stack. If there are two or more vertices on the stack and w > we, add V_I- V to S, pop V
 *                                    off the stack; if there is only one vertex on the stack or Wt <= Wc, push w onto the stack. Repeat this step
 *                                    until the nth vertex has been pushed onto the stack.
 *                                (b) If there are more than three vertices on the stack, add Vt-1-V to $, pop Vt off the stack and repeat this step,
 *                                    else stop
 *
 *                                [PART II]
 *
 *                                THEOREM 1. For every choice of V1,V2,(as prescribed in PartI), if the weights of the vertices of the n-gon satisfy the
 *                                           following condition
 *                                           **FORMULA**
 *                                           for some k, 3 <-k _<-_ n, then every optimum partition of the n-gon contains the k-gon V1- VE Vk.
 *
 *                                THEOREM 2. For every choice of V1, V2, (as prescribed in Part I), if the weights of the vertices satisfy the condition
 *                                           **FORMULA**
 *                                           then V1- V2 and V1- V3 exist in every optimum partition of the n-gon
 *
 *                                THEOREM 3. Let Vx and Vz be two arbitrary vertices which are not adfacent in a polygon, and Vw be the smallest vertex
 *                                           from Vx to Vz in the clockwise manner Vw Vx, Vw Vz), and Vy be the smallest vertex from Vz to Vx in the
 *                                           clockwise manner Vy V, Vy V). This is shown in Fig. 1. Assume that V < Vz and Vy < Vw. The necessary condition
 *                                           for V V to exist as an h-arc in any optimum partition is
 *                                           **FORMULA**
 *
 *                                A partition is called a fan it is consists of only v-arcs joining the smallest vertex to all other vertices in the polygon.
 *
 *                                We shall denote the fan of a polygon V- Vb- V V by Fan (W[Wb, Wc,’’’, W). The smallest vertex V1 is called the center of the fan.
 *
 *                                We define a vertex as a local maximum vertex if it is larger than its two neighbors and define a vertex as a local
 *                                minimum vertex if it is smaller than its two neighbors.
 *
 *                                A polygon is called a monotone polygon if there exist only one local maximum and one local minimum vertex.
 *
 *                                LEMMA 1. If none of the potential h-arcs appears in the 1-optimum partition of the n-gon, the l-optimum partition
 *                                         must be the fan of the n-gon
 *
 *                                LEMMA 2. For any two arcs in P, say V- V. and Vp- Vq, we must have either Vi- V. above Vo Vo or Vo- Vq above Vi- V..
 *                                         Let P be the set of all potential h-arcs in a monotone basic n-gon. P can have at most n- 3 arcs.
 *
 *                                LEMMA 3. Any subpolygon which is bounded by two potential h-arcs of the monotone basic n-gon is itself a monotone polygon.
 *
 *                                LEMMA 4. Any potential h-arc of a subpolygon bounded above and below by two potential h-arcs of the monotone basic n-gon
 *                                         is also a potential h-arc of the monotone basic n-gon.
 *
 *                                We can now summarize what we have discussed. If there is no h-arc in the l-optimum partition of a monotone basic n-gon,
 *                                the l-optimum partition must be a fan. Otherwise, the h-arcs in the l-optimum partition are all layered, one above another.
 *                                If we consider the local maximum vertex V, and the local minimum vertex V1 as two degenerated h-arcs, then the l-optimum
 *                                partition of a monotone basic n-gon will contain one or more monotone subpolygons, each bounded above and below by two h-arcs
 *                                and the/-optimum partition of each of these monotone subpolygons is a fan. Then, in finding the l-optimum partition of a
 *                                monotone basic polygon, we have only to consider those partitions which contain one or more potential h-arcs and each of the
 *                                subpolygons between two potential h-arcs is partitioned by a fan
 *
 *                                An h-arc Vi Vk which divides a polygon into two subpolygons is called a positive arc with respect to the polygon if
 *                                condition (4) is satisfied, Otherwise, it is called a negative arc with respect to the polygon.
 *
 *                                When an n-gon is divided into subpolygons, an h-arc is defined as positive in a subpolygon if the cost of partition of the
 *                                subpolygon with the h-arc as the only h-arc is less than the fan in the subpolygon.
 *
 *                                THEOREM 4. If an h-arc is positive with respect to a polygon then the arc is positive with respect to any subpolygon containing
 *                                           that arc. If an h-arc is positive with respect to a subpolygon, it may or may not be positive with respect to a
 *                                           larger polygon which contains the subpolygon.
 *
 *                                This shows that the existence of an h-arc depends on the existence of another h-arc.
 *
 *                                The left-hand side of (7) is denoted by S(hk\hn), is called the supporting weight of the arc h with respect to the upper
 *                                subpolygon bounded above by hn
 *
 *                                If S(hi\hj)<S(hi\hk), we have S(hi\hj)<S(hi\hk)<S(hi\h). On the other hand, if S(hi\hi)> S(hi\hk), we have
 *                                S(hi\hi)> S(hi\hk)> S(hi\h).
 *
 *                                Define S(h,\h,) to be zero. We say that an arc h is the ceiling of another arc hi if either condition (i) or conditions
 *                                (iia), (iib), and (iic) are satisfied
 *                                **FORMULA**
 *
 *                                We say that an arc hi is a son of another arc hi if the following conditions are satisfied:
 *                                **FORMULA**
 *
 *                                (i) if the father of any arc hj exists in the l-optimum partition, then the arc hj will also exist in the same partition
 *                                (ii) if the father of h does not exist in the l-optimum partition, then the arc h also does not exist in the same partition.
 *
 *                                P11 to be continue
 */
class Matrix_Chain_Multiplication_Problem_Solution
{
public:
    /**
     * @brief default constructor
     */
    Matrix_Chain_Multiplication_Problem_Solution();

    /**
     * @brief set matrices for the problem
     * @param vector<pair<uint32_t, uint32_t>> &vecMatrices, matrices
     * @return void
     * @remarks
     */
    void set_matrices(vector<pair<uint32_t, uint32_t>> &vecMatrices);

    /**
     * @brief show matrices
     * @param
     * @return string
     * @remarks
     */
    string show_matrices() const;

    /**
     * @brief solve problem with dynamic programming bottom up method
     * @param vector<vector<uint32_t>> &matrixMultiplyTimes, multiply times result
     * @param vector<vector<uint32_t>> &matrixBracketPosition, multiply best bracket position
     * @return void
     * @remarks
     */
    void dp_bottom_up_method(vector<vector<uint32_t>> &matrixMultiplyTimes, vector<vector<uint32_t>> &matrixBracketPosition);

    /**
     * @brief show dp_bottom_up_method result
     * @param const vector<vector<uint32_t>> &matrixMultiplyTimes, multiply times result
     * @param const vector<vector<uint32_t>> &matrixBracketPosition, multiply best bracket position
     * @return string, result string
     * @remarks
     */
    string dp_bottom_up_method_show_result(const vector<vector<uint32_t>> &matrixMultiplyTimes,
                                           const vector<vector<uint32_t>> &matrixBracketPosition) const;

private:
    /**
     * @brief show bracket form recursive
     * @param const vector<vector<uint32_t>> &matrixBracketPosition, bracket position result
     * @param size_t nStartIndex, start index for sub problem
     * @param size_t nEndIndex, end index for sub problem
     * @return string, bracket form string
     * @remarks
     */
    string dp_bottom_up_method_show_bracket_form_recursive(const vector<vector<uint32_t>> &matrixBracketPosition, size_t nStartIndex, size_t nEndIndex) const;

private:
    /*< matrices with <rows, columns> */
    vector<pair<uint32_t, uint32_t>> m_vecMatrices;
};

/**
 * @brief test matrix chain multiplication problem solution
 * @param
 * @return void
 * @remarks
 */
void matrix_chain_multiplication_problem_solution_test();

#endif // __MATRIX_CHAIN_MULTIPLICATION_PROBLEM_H__
